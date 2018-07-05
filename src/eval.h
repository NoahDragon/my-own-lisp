#ifndef eval_h
#define eval_h

#ifdef __cplusplus
extern "C" {
#endif

#include "mpc.h"

/* Declare new lval struct */
typedef struct {
    int type;
    long num;
    int err
} lval;

/* Create Eumeration of Possible lval Types */
enum {
    LVAL_NUM,
    LVAL_ERR
};

/* Create Enumeration of Possible Error Types */
enum {
    LERR_DIV_ZERO,
    LERR_BAD_OP,
    LERR_BAD_NUM
};

lval lval_num(long);
lval lval_err(int);
void lval_print(lval);
void lval_println(lval);
lval eval_op(lval, char*, lval);
lval eval(mpc_ast_t*);

#ifdef __cplusplus
}
#endif
#endif
