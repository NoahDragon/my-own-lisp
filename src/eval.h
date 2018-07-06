#ifndef eval_h
#define eval_h

#ifdef __cplusplus
extern "C" {
#endif

#include "mpc.h"
#include "utils.h"

/* Declare new lval struct */
typedef struct lval {
    int type;
    long num;
    /* Error and Symbol types have some string data */
    char* err;
    char* sym;
    /* Count and Pointer to a list of lval */
    int count;
    struct lval** cell;
} lval;

/* Create Eumeration of Possible lval Types */
enum {
    LVAL_NUM,
    LVAL_ERR,
    LVAL_SYM,
    LVAL_SEXPR
};

/* Create Enumeration of Possible Error Types */
enum {
    LERR_DIV_ZERO,
    LERR_BAD_OP,
    LERR_BAD_NUM
};

lval* lval_num(long);
lval* lval_err(char*);
lval* lval_sym(char*);
lval* lval_sexpr(void);
void lval_del(lval*);
void lval_expr_print(lval*, char, char);
void lval_print(lval*);
void lval_println(lval*);
lval* lval_add(lval*, lval*);
lval* lval_read_num(mpc_ast_t*);
lval* lval_read(mpc_ast_t*);
lval* lval_eval_sexpr(lval*);
lval* lval_eval(lval*);
lval* lval_pop(lval*, int);
lval* lval_take(lval*, int);
lval* builtin_op(lval*, char*);

#ifdef __cplusplus
}
#endif
#endif
