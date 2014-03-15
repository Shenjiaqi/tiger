#include "env.h"
#include "util.h"
#include "symbol.h"

E_enventry E_VarEntry(Ty_ty Ty)
{
    E_enventry r = checked_malloc( sizeof(*r) );
    r->kind = E_varEntry;
    r->u.var.ty = Ty;
    return r;
}

E_enventry E_FunEntry(Ty_tyList formals, Ty_ty result)
{
    E_enventry r = checked_malloc( sizeof(*r) );
    r->kind = E_funEntry;
    r->u.fun.formals = formals;
    r->u.fun.result = result;
    return r;
}

S_table E_base_tenv(void)
{
    return S_empty();
}

S_table E_base_venv(void)
{
    return S_empty();
}