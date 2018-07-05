#ifndef eval_h
#define eval_h

#ifdef __cplusplus
extern "C" {
#endif

#include "mpc.h"

long eval_op(long, char*, long);
long eval(mpc_ast_t*);

#ifdef __cplusplus
}
#endif
#endif
