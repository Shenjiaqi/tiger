//functions for semantic check
#include "semant.h"
#include "env.h"
#include "symbol.h"
#include "expty.h"
#include <assert.h>
#include "expty.h"
#include "symbol.h"
#include <stdio.h>
#include <stdlib.h>
#include "prabsyn.h"

S_table tEnvTable, vEnvTable;
// variable expression
static struct expty transVar( S_table venv, S_table tenv, A_var a);
// let statement
static struct expty transLet( S_table venv, S_table tenv, A_exp a);
// declare statement
static struct expty transDec( S_table venv, S_table tenv,
                             A_decList d);
static struct expty transBody( S_table venv, S_table tenv,
                              A_expList a);
static Ty_ty getActuallTy( Ty_ty t);

static char *str_ty[] = {
    "record", "nil", "int", "string",
    "array", "name", "void"};

void SEM_transProg(A_exp exp)
{
    tEnvTable = E_base_tenv();
    vEnvTable = E_base_venv();
//    insert element type to tEnvTable
    S_enter( tEnvTable, S_Symbol("int"), Ty_Int());
    S_enter( tEnvTable, S_Symbol("string"), Ty_String());
    S_enter( tEnvTable, S_Symbol("void"), Ty_Void());
    S_enter( tEnvTable, S_Symbol("nil"), Ty_Nil());
    transExp(vEnvTable, tEnvTable, exp);
}

struct expty transExp(S_table venv, S_table tenv, A_exp a)
{
//    printf("%s %d %d %d\n", __FUNCTION__, a->kind, A_varExp, A_assignExp);
//    pr_exp( stdout, a, 0);
    struct expty r;
    r.exp = NULL, r.ty = Ty_Void();
    switch (a->kind)
    {
        case A_varExp:
            // variable expression
            // id or id.(id.)id or id[] or id.(id.)id[]...
            r = transVar( venv, tenv, a->u.var);
            break;
        case A_letExp:
            r = transLet( venv, tenv, a);
            break;
        case A_nilExp:
            r.exp = NULL;
            r.ty = Ty_Nil();
            break;
        case A_intExp:
            r.ty = Ty_Int();//S_look(tenv, S_Symbol("int"));
            r.exp = NULL;
            break;
        case A_recordExp:
        {
            S_symbol tyName = a->u.record.typ;
            Ty_ty prety = S_look( tenv, tyName);
            if( prety == NULL )
            {
                EM_error( a->pos, " type \"%s\" not defined", S_name(tyName));
                r.ty = Ty_Void();
            }
            else
            {
                A_efieldList fields = a->u.record.fields;
                prety = getActuallTy( prety);
                if( prety->kind != Ty_record )
                {
                    EM_error( a->pos, " type \"%s\" is not a record",
                             S_name(tyName));
                }
                else
                {
//                TODO: now we allow reassignment and aprtial assignment
                    for(A_efieldList i = fields; i != NULL ; i = i->tail )
                    {
                        A_efield ii = i->head;
//                        find corresponding field in record declarations
                        Ty_fieldList j = prety->u.record;
                        for(; j != NULL; j = j->tail)
                        {
                            Ty_field jj = j->head;
                            if( jj->name == ii->name )
                                break;
                        }
                        if( j == NULL )
                        {
                            EM_error(a->pos, " cann't find field \"%s\" in \"%s\"",
                                     S_name(ii->name),
                                     S_name(tyName));
                        }
                        else
                        {
//                            eval exp
                            r = transExp( venv, tenv, ii->exp);
                            Ty_ty tyexp = getActuallTy(r.ty);
                            Ty_field jj = j->head;
                            Ty_ty tyExpect = getActuallTy(jj->ty);
                            if( tyExpect->kind != tyexp->kind &&
                               tyexp->kind != Ty_nil )// nil belong to any type
                            {
                                EM_error(a->pos, "type of expression(%s) of \"%s\" does not match declatation(%s)",
                                         str_ty[tyexp->kind], S_name(ii->name),
                                         str_ty[tyExpect->kind]);
                            }
                        }
                    }
                }
                r.ty = prety;
            }
            break;
        }
        case A_stringExp:
            r.exp = NULL;
            r.ty = Ty_String();
            break;
        case A_assignExp:
        {
            A_var var = a->u.assign.var;
            A_exp exp = a->u.assign.exp;
            struct expty varexp = transVar( venv, tenv, var);
            struct expty exprexp = transExp( venv, tenv, exp);
            Ty_ty varty = varexp.ty;
            Ty_ty exprty = getActuallTy( exprexp.ty );
            if( varty != exprty && exprty->kind != Ty_void )
            {
                if( varty->kind == Ty_record && exprty->kind == Ty_record)
                    EM_error( a->pos, " assignment between different records");
                else
                    EM_error( a->pos, " type doesn't match int assigment, from %s to %s",
                         str_ty[exprty->kind], str_ty[varty->kind]);
            }
            break;
        }
        default:
//            assert(0);
            break;
    }
    return r;
}
//lvalue
static struct expty transVar( S_table venv, S_table tenv, A_var a)
{
//    printf("%s\n", __FUNCTION__);
    struct expty r;
    r.exp = NULL, r.ty = Ty_Void();
    switch (a->kind)
    {
        case A_simpleVar:
        {
//            var id
            S_symbol varName = a->u.simple;
            Ty_ty prety = getActuallTy(S_look( venv, varName));
            if( prety == NULL )
            {
                EM_error( a->pos, " \"%s\" not defined yet",
                         S_name( varName));
            }
            else r.ty = prety;
            break;
        }
        case A_fieldVar:
        {
//            id.id
            S_symbol sym = a->u.field.sym;
            A_var var = a->u.field.var;
            struct expty tr = transVar( venv, tenv, var);
            Ty_ty typeVar = getActuallTy(tr.ty);
            if( typeVar->kind != Ty_record )
            {
                printf("%s\n", str_ty[typeVar->kind]);
                EM_error( a->pos, " \"%s\" is not a valid field",
                         S_name(sym) );
            }
            else
            {
//                find if sym is a field
                bool ok = FALSE;
                for( Ty_fieldList i = typeVar->u.record; i != NULL;
                    i = i->tail )
                {
                    Ty_field field = i->head;
                    if( field->name == sym )
                    {
                        r.ty = field->ty;
                        ok = TRUE;
                        break;
                    }
                }
                if( !ok )
                {
                    EM_error( a->pos, " cann't find field \"%s\"",
                             S_name(sym));
                }
            }
            break;
        }
        case A_subscriptVar:
        {
//            a[b]
            A_var var = a->u.subscript.var;
            A_exp exp = a->u.subscript.exp;
//            trans over a
            struct expty varexp = transVar( venv, tenv, var);
            Ty_ty varty = getActuallTy(varexp.ty);
            if( varty->kind != Ty_array )
            {
                EM_error( a->pos, " expression/ variable is not array");
            }
            else
            {
//                trans over b
                struct expty exprexp = transExp( venv, tenv, exp);
                if( exprexp.ty->kind != Ty_int )
                {
                    EM_error( a->pos, " expect int expression, not %s",
                             str_ty[exprexp.ty->kind]);
                }
                r.exp = NULL;
                r.ty = getActuallTy(varty->u.array);
            }
            break;
        }
        default:
            assert(0);
            break;
    }
    return r;
}

static struct expty transLet( S_table venv, S_table tenv, A_exp a)
{
//    printf("%s\n", __FUNCTION__);
    S_beginScope(venv);
    S_beginScope(tenv);
    struct expty r = transDec( venv, tenv, a->u.let.decs);
    r = transBody( venv, tenv, a->u.let.body);
    S_endScope(venv);
    S_endScope(tenv);
    return r;
}
struct lst
{
    void * v;
    struct lst * nxt;
};
struct lst * addLst(  void * v, struct lst * pre)
{
    struct lst * tmp = (struct lst *)checked_malloc( sizeof( struct lst ) );
    tmp->v = v, tmp->nxt = pre;
    return tmp;
}
//static
static struct expty transDec( S_table venv, S_table tenv,
                             A_decList d)
{
//    printf("%s\n", __FUNCTION__);
    struct expty r;
    r.exp = NULL, r.ty = Ty_Void();
    Ty_tyList tyList = NULL;
    for( A_decList i = d; i != NULL; i = i->tail )
    {
        A_dec d = i->head;
        r.exp = NULL, r.ty = Ty_Void();
        switch (d->kind)
        {
            case A_functionDec:
                break;
            case A_varDec:
            {
                S_symbol var = d->u.var.var;
                Ty_ty preVar = (Ty_ty)S_look( venv, var);
                if( preVar != NULL )
                {
                    // redefination
                    EM_error( d->pos, "varibale \"%s\" already defined at",
                             S_name(var));
//                    TODO: previous definition position
//                    EM_error( preVar->pos, "variable \"%s\"
//                    first defined here",
//                             S_name(var));
                }
                else
                {
                    S_symbol type = d->u.var.typ;
                    A_exp init = d->u.var.init;
                    struct expty tyexp = transExp( venv, tenv, init);
                    Ty_ty tydec = NULL;
                    if( tyexp.ty->kind == Ty_void )
                    {
                        EM_error( d->pos, "expect typed expression");
                    }
                    else if( type == NULL )
                    {
//                      expression must return a typed value
                        if( tyexp.ty->kind == Ty_nil )
                            EM_error( d->pos, "cannot assign nil to \
                                     variable \"%s\" with no declared \
                                     type", S_name(var) );
                        else
                            tydec = tyexp.ty;
                    }
                    else
                    {
                        tydec = (Ty_ty) S_look( tenv, type);
                    }
                    tydec = getActuallTy( tydec );
                    if( tydec == NULL )
                    {
                        EM_error( d->pos, "type \"%s\" not declared",
                                 S_name(type) );
                    }
//                        compare with address, not element of ty
                    else if( tydec != tyexp.ty )
                    {
                        EM_error( d->pos,
                                 " type of variable \"%s\"(%s) does not\
                                 match with typeof expression(%s)",
                                 S_name(var), S_name(type),
                                 str_ty[tyexp.ty->kind]);
                    }
                    else
                    {
//                        bool escape = d->u.var.escape;
                        r.exp = NULL;
                        r.ty = tydec;
//                        insert var to table
                        S_enter( venv, var, tydec);
                    }
                }
                break;
            }
            case A_typeDec:
            {
                struct lst * toFill = NULL;
                for( A_nametyList i = d->u.type; i != NULL; i = i->tail)
                {
                    A_namety n = i->head;
                    S_symbol name = n->name;
//                    check if previous definition exist
                    Ty_ty redef = S_look( tenv, name );
                    if( redef != NULL )
                    {
                        EM_error( d->pos, " type \"%s\"\
                                 already defined", S_name(name));
//                        TODO print previous definitation position
//                        EM_error( d->pos, " type \"%s\"\
//                                 defined here");
                    }
                    A_ty ty = n->ty;
                    S_symbol tyname = ty->u.name;
                    switch( ty->kind )
                    {
                        case A_nameTy:
                        {
//                            type i = name
                            Ty_ty prety = getActuallTy(S_look( tenv, tyname));
                            if( prety == NULL )
                            {
//                                type must be declared before
                                EM_error( d->pos, "\"%s\" not defined\
                                         yet", S_name(tyname));
                            }
                            else
                            {
                                r.exp = NULL;
                                r.ty = prety;
                                S_enter( tenv, name, r.ty);
                            }
                            break;
                        }
                        case A_recordTy:
                        {
                            Ty_fieldList fieldList = NULL;
                            for( A_fieldList j = ty->u.record; j != NULL;
                                j = j->tail)
                            {
                                A_field k = j->head;
//                            TODO: check duplicate field name
                                S_symbol fieldName = k->name;
                                S_symbol fieldTypeName = k->typ;
                                Ty_ty preTy =
                                getActuallTy((Ty_ty)S_look(tenv, fieldTypeName));
                                if( preTy == NULL )
                                {
//                                    type of field not defined yet
//                                    may defined after
                                    preTy = Ty_Name( fieldTypeName, NULL);
//                                    fill NULL with address laster
                                    toFill = addLst( preTy, toFill);
                                }
                                fieldList =
                                Ty_FieldList( Ty_Field( fieldName, preTy),
                                             fieldList );

//                                Ty_field tyField =
//                                Ty_Field( fieldName, )
                            }
                            r.exp = NULL;
                            r.ty = Ty_Record(fieldList);
                            S_enter( tenv, name, r.ty);
                            break;
                        }
                        case A_arrayTy:
                        {
                            S_symbol typeName = ty->u.array;
                            Ty_ty prety = getActuallTy(S_look( tenv, typeName));
                            if( prety == NULL )
                            {
//                                not defined yet
                                prety = Ty_Name( typeName, NULL);
                                toFill = addLst( prety, toFill);
                            }
                            r.exp = NULL, r.ty = Ty_Array( prety );
                            S_enter( tenv, name, r.ty);
                            break;
                        }
                        default:
                            break;
                    }
//                    add to tyList, in reverse order
                    tyList = Ty_TyList( r.ty, tyList);
                }
//                fill back ty_name
                for( struct lst * i = toFill; i != NULL; )
                {
                    S_symbol typeName = ((Ty_ty) i->v)->u.name.sym;
                    Ty_ty ty = S_look( tenv, typeName);
                    Ty_ty fill = (Ty_ty) i->v;
                    if( ty == NULL )
                    {
//                        TODO: pos info
                        EM_error( d->pos, "\"%s\" not defined",
                                 S_name(typeName) );
                    }
                    else
                    {
                        assert( fill->kind == Ty_name );
                        fill->u.name.ty = ty;
                    }
                    typeof(i) j = i;
                    i = i->nxt;
                    free(j);
                }
                break;
            }
            default:
                break;
        }
    }
    r.exp = NULL, r.ty = NULL;
//    TyList_print(tyList);
    return r;
}

static struct expty transBody( S_table venv, S_table tenv, A_expList a)
{
    struct expty r;
    r.exp = NULL, r.ty = Ty_Void();
    for( A_expList i = a; i != NULL; i = i->tail)
    {
        r = transExp( venv, tenv, i->head);
    }
    return r;
}

static Ty_ty getActuallTy( Ty_ty t)
{
    if( t != NULL && t->kind == Ty_name )
    {
        return getActuallTy( t->u.name.ty);
    }
    return t;
}
