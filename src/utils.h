#ifndef utils_h
#define utils_h

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LISP_NAME "MOL" //Stand for my own lisp.

char* lang_name_string_builder(char*);
void strcpy_with_malloc(char**, char*);

#ifdef __cplusplus
}
#endif
#endif
