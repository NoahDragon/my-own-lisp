#include "utils.h"

char* lang_name_string_builder(char* str){
    int total_len = strlen(str) + strlen(LISP_NAME) + 1;
    char * buffer = malloc(sizeof(char) *total_len);
    strncpy(buffer, LISP_NAME,total_len);
    strncat(buffer, str, total_len - strlen(buffer));
    buffer[total_len - 1] = '\0';
    return buffer;
}

void strcpy_with_malloc(char** t, const char* s){
    *t = malloc(strlen(s) + 1);
    strcpy(*t, s);
}
