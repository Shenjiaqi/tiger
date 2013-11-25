#ifndef _SEMANT_H_
#define _SEMANT_H_
#include <stdio.h>
#include "util.h"
#include "absyn.h"
#include "types.h"
#include "symbol.h"
#include "errormsg.h"
typedef void* Tr_exp;
struct expty { Tr_exp exp; Ty_ty ty; };
struct expty _expTy(Tr_exp exp, Ty_ty ty);
struct expty transExp(S_table venv, S_table tenv, A_exp a);
struct expty transVar(S_table venv, S_table tenv, A_var v);
struct expty transDec(S_table venv, S_table tenv, A_exp d);
/* struct Ty_ty transTy( S_table tenv, A_ty a); */
#endif
