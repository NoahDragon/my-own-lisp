#include <stdio.h>
#include <stdlib.h>

#define LISP_NAME "MOL" //Stand for my own lisp.
#define MAX_STRING_LENGTH 1024

/* If we are compiling on Windows compile these functions */
#ifdef _WIN32
#include <string.h>
static char buffer[2048];
/* Fake readline function */
char* readline(char* prompt) {
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer)+1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy)-1] = '\0';
    return cpy;
}
/* Fake add_history function */
void add_history(char* unused) {}
/* Otherwise include the editline headers */
#else
/* Use the readline lib to solve the arrow keys issue in Unix system */
#include <editline/readline.h>
#include <editline/history.h>
#endif

char * lang_name_string_builder(const char *str){
    int total_len = strlen(str) + strlen(LISP_NAME) + 1;
    char * buffer = malloc(sizeof(char) *total_len);
    strncpy(buffer, LISP_NAME,total_len);
    strncat(buffer, str, total_len - strlen(buffer));
    buffer[total_len - 1] = '\0';
    return buffer;
}

int main(int argc, char** argv) {
    puts(lang_name_string_builder(" Version 0.0.0.0.1"));
    puts("Press Ctrl+c to Exit\n");
    while (1) {
        /* Now in either case readline will be correctly defined */
        char* input = readline(lang_name_string_builder("> "));
        add_history(input);
        printf("No you're a %s\n", input);
        free(input);
    }
    return 0;
}