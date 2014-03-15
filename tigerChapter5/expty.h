#ifndef _EXPTY_H_
#define _EXPTY_H_
//struct expty stores translated representation and its type
#include "types.h"
typedef void * Tr_exp;
struct expty
{
    Tr_exp exp;
    Ty_ty ty;
};
struct expty expTy(Tr_exp exp, Ty_ty ty);
#endif