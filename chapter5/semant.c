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

//indicate whether in funcdeclare
static bool inFunc;
void SetInFunc()
{
  inFunc = TRUE ;
}
void UsetInFunc()
{
  inFunc = FALSE;
}
bool InFunc()
{
  return inFunc;
}
//

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
  if( funentry == NULL)
    EM_error( e->pos , S_name( e->u.call.func ) , "not defined" );
  if( funentry->kind != E_funEntry )
    EM_error( e->pos , S_name( e->u.call.func ) , "is not function name" );
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
	struct expty var =  transVar( venv , tenv , v->u.field.var);
	Ty_ty varType = var.ty;
	string fieldName = S_name( v->u.field.sym );
	if( varType->kind != Ty_record )
	  EM_error( v->pos , " is not record " );
	Ty_fieldList fields = varType->u.record;
	for( ; fields != NULL ; fields = fields->tail )
	  {
	    Ty_field field = fields->head ;
	    if( field->name == v->u.field.sym )
	      return _expTy( NULL , field->ty );
	  }
	EM_error( v->pos , "can't find field " , S_name( v->u.field.sym ) );
      }
    case A_subscriptVar:
      {
	struct expty var = transVar( venv , tenv , v->u.subscript.var );
	struct expty subs = transExp( venv , tenv , v->u.subscript.exp );
	if( subs.ty->kind != Ty_int )
	  EM_error( v->pos , "array subs should be int" );
	return var;
      }
    default :
      assert(0);
    }
}
static Ty_ty dfsTypeDec( A_pos pos , S_table tenv ,
			 S_symbol s , S_symbol origin )
{
  if( s == origin )
    {
      EM_error( pos , " loop in definition " , S_name(s) );
      return NULL ;
    }

  Ty_ty ty = S_look( tenv , s );
  if( ty == NULL )
    EM_error( pos , " can't find " , s );

  if( ty->kind == Ty_name )
    {
      if( ty->u.name.ty == NULL )
	ty->u.name.ty = dfsTypeDec( pos , tenv , ty->u.name.sym , origin );
      return ty->u.name.ty;
    }
  return ty;
}
static Ty_fieldList dfsRecordTy( S_table tenv , A_fieldList records )
{
  if( records == NULL )
    return NULL ;
  A_field record = records->head ;
  Ty_ty type = S_look( tenv , record->typ );
  Ty_field field;
  if( type == NULL )
    field = Ty_Field( record->name , Ty_Name( record->typ , NULL ) );
  else field = Ty_Field( record->name , type );
  Ty_fieldList rest = dfsRecordTy( tenv , records->tail );
  return Ty_FieldList( field , rest );
}
struct expty transDec(S_table venv, S_table tenv, A_dec d)
{
  switch( d->kind )
    {
    case A_functionDec:
      {
	//whether already in funcdeclar
	if(InFunc())
	  EM_error( d->pos , "already in func declare");
	A_fundecList funcs = d->u.function;
	// for every fun declare in fundecList
	for( ; funcs != NULL ; funcs = funcs->tail )
	  {
	    A_fundec func = funcs->head;
	    // get ty of params and result
	    Ty_tyList funentry = makeFormalTyList( tenv , func->params );
	    Ty_ty res;
	    if( func->result == NULL )
	      res = Ty_Nil();
	    else
	      res = S_look( tenv , func->result );
	    if( res == NULL )
	      EM_error( func->pos , "no " , S_name( func->result ) , "type ");
	    //whether already defined
	    if( S_look( venv , func->name ) != NULL )
	      EM_error( func->pos , S_name( func->result ) ,
			"already defined" );
	    S_enter( venv ,  func->name , E_FunEntry( funentry , res ) );
	  }
	funcs = d->u.function;
	// for every fun in fundecList, call tranexp on its body
	for( ; funcs != NULL ; funcs = funcs->tail )
	  {
	    A_fundec func = funcs->head;
	    S_beginScope( venv );
	    A_fieldList args = func->params;
	    Ty_tyList funentries = ((E_entry)S_look( venv , func->name ))
	      ->fun.formalTys ;
	    for( ; args != NULL ; args = args->tail ,
		   funentries = funentries->tail)
	      {
		A_field arg = args->head;
		Ty_ty type = funentries->head;
		S_enter( venv , arg->name , type );
	      }
	    SetInFunc();
	    transExp( venv , tenv , func->body );
	    UsetInFunc();
	    S_endScope( venv );
	  }
	return _expTy( NULL , Ty_Void() );
      }
    case A_varDec:
      {
	Ty_ty type = S_look( tenv , d->u.var.typ );
	if( type == NULL )
	  EM_error( d->pos , S_name( d->u.var.typ ) , " not defined " );
	struct expty init = transExp( venv , tenv , d->u.var.init );
	if( init.ty->kind != Ty_nil && init.ty->kind != type->kind )
	  EM_error( d->pos , "Expect " , tyKindName( type->kind ) , " but " ,
		    tyKindName( init.ty->kind ) );
	if( S_look( venv , d->u.var.var ) != NULL )
	  EM_error( d->pos , S_name( d->u.var.var ) , " already defined " );
	S_enter( venv , d->u.var.var , type );
	return _expTy( NULL , Ty_Void() );
      }
    case A_typeDec:
      {
	A_nametyList tylist = d->u.type;
	for( ; tylist != NULL ; tylist = tylist->tail )
	  {
	    A_namety tydec = tylist->head;
	    if( S_look( tenv , tydec->name ) != NULL )
	      EM_error( tydec->ty->pos , S_name( tydec->name ) ,
			" already declared " );
	    A_ty ty = tydec->ty;
	    switch( ty->kind )
	      {
	      case A_nameTy:
		{
		  Ty_ty tyy = S_look( tenv , ty->u.name ) ;
		  if( tyy == NULL )
		    S_enter( tenv , tydec->name ,
			     Ty_Name( ty->u.name , NULL ) );
		  else
		    S_enter( tenv , tydec->name , tyy );
		}
	      case A_recordTy:
		{
		  A_fieldList records = ty->u.record;
		  Ty_fieldList types = dfsRecordTy( tenv , records );
		  S_enter( tenv , tydec->name , Ty_Record( types ) );
		}
	      case A_arrayTy:
	      default:
		assert(0);
	      }
	    S_enter( tenv , tydec->name , E_VarEntry( NULL ) );
	  }
	tylist = d->u.type;
	for( ; tylist != NULL ; tylist = tylist->tail )
	  {
	    A_namety tydec = tylist->head;
	    A_ty ty = tydec->ty;
	    switch( ty->kind )
	      {
	      case A_nameTy:
		{
		  Ty_ty tyy = S_look( tenv , ty->u.name );
		  if( tyy->u.name.ty == NULL )
		    tyy->u.name.ty = dfsTypeDec( ty->pos , tenv ,
						 tyy->u.name.sym ,
						 tydec->name );
		}
	      case A_recordTy:
	      case A_arrayTy:
	      default:
		assert(0);
	      }
	  }
      }
    default:
      assert(0);
    }
}
/* struct Ty_ty transTy( S_table tenv, A_ty a) */
/* {} */
