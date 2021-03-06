#include "parsing.h"

void prepareMOL(){
    Number = mpc_new("number");
    Symbol = mpc_new("symbol");
    Sexpr = mpc_new("sexpr");
    Qexpr = mpc_new("qexpr");
    Expr = mpc_new("expr");
    Lispy = mpc_new("lispy");

    mpca_lang(MPCA_LANG_DEFAULT,
    "                                                       \
        number      : /-?[0-9]+/ ;                          \
        symbol      : /[a-zA-Z0-9_+\\-*\\/\\\\=<>!&]+/ ;    \
        sexpr       : '(' <expr>* ')' ;                     \
        qexpr       : '{' <expr>* '}' ;                     \
        expr        : <number> | <symbol> | <sexpr>         \
                    | <qexpr> ;                             \
        lispy       : /^/ <expr>* /$/ ;                     \
    ",
    Number, Symbol, Sexpr, Qexpr, Expr, Lispy);

    e = lenv_new();
    lenv_add_builtins(e);
}

void clearMOL(){
    mpc_cleanup(6, Number, Symbol, Sexpr, Qexpr, Expr, Lispy);
}

void stdin_parser(const char* input){
    /* Attempt to parse the user input */
    mpc_result_t r;
    if(mpc_parse("<stdin>", input, Lispy, &r)) {
        lval* result = lval_eval(e, lval_read(r.output));
        //lval* result = lval_read(r.output);
        lval_println(result);
        lval_del(result);
        mpc_ast_delete(r.output);
    } else {
        /* Otherwise print and delete the Error */
        mpc_err_print(r.error);
        mpc_err_delete(r.error);
    }
}
