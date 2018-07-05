#include "parsing.h"

void polish_notation(){
    Number = mpc_new("number");
    Operator = mpc_new("operator");
    Expr = mpc_new("expr");
    Lispy = mpc_new("lispy");

    mpca_lang(MPCA_LANG_DEFAULT,
    "                                                       \
        number      : /-?[0-9]+/ ;                          \
        operator    : '+' | '-' | '*' | '/';                \
        expr        : <number> | '(' <operator> <expr>+ ')';\
        lispy       : /^/ <operator> <expr>+ /$/ ;          \
    ",
    Number, Operator, Expr, Lispy);
}

void clear_polish_notation(){
    mpc_cleanup(4, Number, Operator, Expr, Lispy);
}

void stdin_parser(const char* input){
    /* Attempt to parse the user input */
    mpc_result_t r;
    if(mpc_parse("<stdin>", input, Lispy, &r)) {
        long result = eval(r.output);
        printf("%li\n", result);
        mpc_ast_delete(r.output);
    } else {
        /* Otherwise print and delete the Error */
        mpc_err_print(r.error);
        mpc_err_delete(r.error);
    }
}
