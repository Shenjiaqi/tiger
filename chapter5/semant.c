#include "semant.h"
#include "types.h"
#include "util.h"
#include <assert.h>
#define TR(a,b) for(typeof(b) (a)=(b);(a)!=NULL;a=((a)->tail))
typedef struct E_entry_ * E_entry;
struct E_entry_
{
  enum { E_funEntry, E_varEntry } kind;
  union
  {
    struct
    {
      Ty_tyList formalTys;
      Ty_ty resultTy;
    } fun;
    Ty_ty var;
  };
};
struct expty _expTy(Tr_exp exp, Ty_ty ty)
{
  struct expty e;
  e.exp = exp;
  e.ty = ty;
  return e;
}
E_entry E_FunEntry( Ty_tyList arg, Ty_ty ret )
{
  E_entry e = checked_malloc( sizeof( *e ) );
  e->kind = E_funEntry, e->fun.formalTys = arg, e->fun.resultTy = ret ;
  return e;
}
E_entry E_VarEntry( Ty_ty ty )
{
  E_entry e = checked_malloc( sizeof( *e ) );
  e->kind = E_varEntry, e->var = ty;
  return e;
}
static string tyKindName(int k)
{
  switch(k)
    {
    case Ty_record: return "record";
    case Ty_nil: return "nil";
    case Ty_int: return "int";
    case Ty_string: return "string";
    case Ty_array: return "array";
    case Ty_name: return "name";
    case Ty_void: return "void";
    default: assert(0);
    }
  return NULL;
}

static void  assertKind( int pos, int kind, int k, string s)
{
  if( kind !=k )
    EM_error( pos, "Expect %s ", s );
}

Ty_tyList makeFormalTyList( S_table tenv, A_fieldList args)
{
  if( args == NULL )
    return NULL;
  A_field arg = args->head;
  Ty_ty ty = S_look( tenv, arg->typ );
  if( ty == NULL )
    EM_error( arg->pos, "wrong ty");
  return Ty_TyList( ty, makeFormalTyList( tenv, args->tail ) );
}

//check function call exp
static struct expty transExpCall( S_table venv, S_table tenv, A_exp e)
{
  //make sure e is funcall, just in case
  assertKind( e->pos, e->kind, A_callExp , "function call" );

  //find function type in tenv
  E_entry funentry = (E_entry)S_look( venv, e->u.call.func );
  //may be not a function name or can't find at all
  if( funentry == NULL || funentry->kind != E_funEntry )
    EM_error( e->pos, S_name( e->u.call.func ) , "is not function name" );
  //traverse all arguments 
  Ty_tyList params = funentry->fun.formalTys;
  A_expList args = e->u.call.args;
  for( ; args!=NULL && params!=NULL ; 
       args = args->tail, params = params->tail )
    {
      Ty_ty param = params->head;
      //evaluate argument exp first
      A_exp arg = args->head;
      struct expty exp = transExp( venv, tenv, arg );
      assertKind( arg->pos, exp.ty->kind , param->kind ,
		  tyKindName(param->kind) );
    }
  //if argument number satisfy argument list in function
  if( args != NULL )
    EM_error( e->pos, "Too much arguments" );
  else if( params != NULL )
    EM_error( e->pos, "Expect more arguments" );
  return _expTy( NULL, funentry->fun.resultTy );
}

struct expty transExp(S_table venv, S_table tenv, A_exp a)
{
  /* S_beginScope(venv); */
  /* S_beginScope(tenv); */
  switch(a->kind)
    {
    case A_varExp:
      return transVar( venv , tenv , a->u.var );
      break;
    case A_nilExp:
      return _expTy( NULL, Ty_Nil() );
      break;
    case A_intExp:
      return _expTy( NULL, Ty_Int() );
      break;
    case A_stringExp:
      return _expTy( NULL, Ty_String() );
      break;
    case A_callExp:
      return transExpCall( venv, tenv, a );
      break;
    case A_opExp:
    case  A_recordExp:
    case  A_seqExp:
    case  A_assignExp:
    case  A_ifExp:
    case A_whileExp:
    case  A_forExp:
    case  A_breakExp:
    case  A_letExp:
    case  A_arrayExp:
      //break;
    default: assert(0);
    }
  /* S_endScope(tenv); */
  /* S_endScope(venv); */
}

//
struct expty transVar(S_table venv, S_table tenv, A_var v)
{

  switch( v->kind )
    {
    case A_simpleVar:
      {
	string varName = S_name( v->u.simple );
	E_entry var = (E_entry) S_look( venv , v->u.simple );
	if( var == NULL )
	  EM_error( v->pos , "can't find" , varName);
	if( var->kind != E_varEntry )
	  EM_error( v->pos , varName , " is not variable " );
	return _expTy( NULL , var->var );
      }
    case A_fieldVar:
      {
	expty var = (expty) transVar( venv , tenv , v->u.field.var);
	Ty_ty varType = var->ty.u.record;
	//TODO
	string varName = S_name( v->u.field.var );
	E_entry var = (E_entry) S_look( venv , v->u.field.var );
	if( var == NULL )
	  EM_error( v->pos , "can't find" , varName );
	if( var->ty.kind != Ty_record )
	  EM_error( v->pos , varName , "is not record type" );
	string fieldName = S_name( v->u.field.sym );
	Ty_fieldList fields = var->ty.u.record;
	for( ; fields != NULL ; fields = fields->tail )
	  if( fields->head->name == sym )
	    return _expTy( NULL , fields->head->ty );
	EM_error( v->pos , varName , " has not field: " , fieldName );
      }
    case A_subscriptVar:
    default :
      assert(0);
    }
}
struct expty  transDec(S_table venv, S_table tenv, A_exp d)
{}
/* struct Ty_ty transTy( S_table tenv, A_ty a) */
/* {} */
