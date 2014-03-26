#ifndef _ENV_H_
#define _ENV_H_
//struct and functions for maintaining
//type table and variable, function table

#include "symbol.h"
#include "types.h"
typedef struct E_enventry_ *E_enventry;
struct E_enventry_
{
    enum
    {
        E_varEntry,
        E_funEntry
    } kind;
    union
    {
        struct
        {
            Ty_ty ty;
        } var;
        struct
        {
//            change from Ty_tyList, different from book
            Ty_fieldList formals;
            Ty_ty result;
        } fun;
    } u;
};

//create variable environment entry
E_enventry E_VarEntry(Ty_ty Ty);

//create an environment entry for function
E_enventry E_FunEntry(Ty_fieldList formals, Ty_ty result);

//return an environment table for variable and function
S_table E_base_tenv(void);

//return an environment table for type
S_table E_base_venv(void);
#endif