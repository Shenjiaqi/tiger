//functions for semantic check
#include "semant.h"
#include "env.h"
#include "symbol.h"
#include "expty.h"

struct expty transExp(S_table venv, S_table tenv, A_exp a);

S_table tEnvTable, vEnvTable;
void SEM_transProg(A_exp exp)
{
    tEnvTable = E_base_tenv();
    vEnvTable = E_base_venv();
    transExp(vEnvTable, tEnvTable, exp);
}

struct expty transExp(S_table venv, S_table tenv, A_exp a)
{
    switch (a->kind)
    {
        case A_varExp:
            // variable expression
            // id or id.(id.)id or id[] or id.(id.)id[]
            
            break;
//
//        default:
//            break;
    }
}
