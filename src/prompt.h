#ifndef prompt_h
#define prompt_h

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

#include "parsing.h"
#include "utils.h"

void prompt(int argc, char** argv);
#ifdef __cplusplus
}
#endif

#endif