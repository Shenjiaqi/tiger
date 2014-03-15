#ifndef _SEMANT_H_
#define _SEMANT_H_
#include <stdio.h>
#include "util.h"
#include "absyn.h"
#include "types.h"
#include "symbol.h"
#include "errormsg.h"
void SEM_transProg(A_exp exp);
struct expty transExp(S_table venv, S_table tenv, A_exp a);
#endif
