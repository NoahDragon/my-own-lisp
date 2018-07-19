#ifndef parsing_h
#define parsing_h

#ifdef __cplusplus
extern "C" {
#endif

#include "mpc.h"
#include "eval.h"

mpc_parser_t* Number;
mpc_parser_t* Symbol;
mpc_parser_t* Sexpr;
mpc_parser_t* Qexpr;
mpc_parser_t* Expr;
mpc_parser_t* Lispy;
lenv* e;

void prepareMOL();
void clearMOL();
void stdin_parser(const char*);

#ifdef __cplusplus
}
#endif

#endif
