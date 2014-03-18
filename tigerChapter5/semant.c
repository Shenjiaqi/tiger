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

S_table tEnvTable, vEnvTable;
// variable expression
static struct expty transVar( S_table venv, S_table tenv, A_var a);
// let statement
static struct expty transLet( S_table venv, S_table tenv, A_exp a);
// declare statement
static struct expty transDec( S_table venv, S_table tenv,
                             A_decList d);

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
//    printf("%s %d %d %d\n", __FUNCTION__, a->kind, A_varExp, A_letExp);
    struct expty r;
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
        default:
//            assert(0);
            break;
    }
    return r;
}

static struct expty transVar( S_table venv, S_table tenv, A_var a)
{
    struct expty r;
    r.exp = NULL, r.ty = NULL;
    switch (a->kind)
    {
        case A_simpleVar:
        {
//            var id
            S_symbol varName = a->u.simple;
//            r = expTy( NULL, );
            break;
        }
        case A_fieldVar:
        {
//            id.id
            S_symbol sym = a->u.field.sym;
            A_var var = a->u.field.var;
            struct expty r = transVar( venv, tenv, var);
            
        }
            break;
        case A_subscriptVar:
            break;
        default:
            assert(0);
            break;
    }
}

static struct expty transLet( S_table venv, S_table tenv, A_exp a)
{
//    printf("%s\n", __FUNCTION__);
    S_beginScope(venv);
    S_beginScope(tenv);
    struct expty r = transDec( venv, tenv, a->u.let.decs);
//    transBofy( venv, tenv, a->u.body);
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
    r.exp = NULL, r.ty = NULL;
    for( A_decList i = d; i != NULL; i = i->tail )
    {
        A_dec d = i->head;
        switch (d->kind)
        {
            case A_functionDec:
                break;
            case A_varDec:
            {
//                printf("varDEc\n");
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
                    S_symbol type = d->u.var.type;
                    A_exp init = d->u.var.init;
                    struct expty tyexp = transExp( venv, tenv, init);
                    Ty_ty tydec;
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
                                     type", var);
                        else
                            tydec = tyexp.ty;
                    }
                    else
                    {
                        tydec = (Ty_ty) S_look( tenv, type);
                    }

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
                                 match with typeof expression",
                                 var, type);
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
                    Ty_ty prety = S_look( tenv, name );
                    if( prety != NULL )
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
                            prety = S_look( tenv, tyname);
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
                                S_symbol fieldName = k->name;
                                S_symbol fieldTypeName = k->typ;
                                Ty_ty preTy =
                                (Ty_ty)S_look(tenv, fieldTypeName);
                                if( preTy == NULL )
                                {
//                                    type of field not defined yet
//                                    may defined after
                                    preTy = Ty_Name( fieldTypeName, NULL);
//                                    fill NULL with address laster
                                    toFill = addLst( preTy, toFill);
                                }
                                Ty_Field( fieldName, preTy);
                                fieldList =
                                Ty_FieldList( Ty_Field( fieldName, preTy),
                                             fieldList );
//                                Ty_field tyField =
//                                Ty_Field( fieldName, )
                            }
                            r.exp = NULL;
                            r.ty = Ty_Record( fieldList);
                            S_enter( tenv, name, r.ty);
                            break;
                        }
                        case A_arrayTy:
                            break;
                        default:
                            break;
                    }
                }
                for( struct lst * i = toFill; i != NULL; )
                {
                    S_symbol typeName = ((Ty_ty) i->v)->u.name.sym;
                    Ty_ty ty = S_look( tenv, typeName);
                    if( ty == NULL )
                    {
//                        TODO: pos info
                        EM_error( d->pos, "\"%s\" not defined",
                                 S_name(typeName) );
                    }
                    else
                    {
                        ((Ty_ty) i->v)->u.name.ty = ty;
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
    return r;
}