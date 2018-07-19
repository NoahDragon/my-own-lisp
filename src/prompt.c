#include "prompt.h"

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
#ifdef __linux__
#include <editline/readline.h>
#include <editline/history.h>
#endif

#ifdef __MACH__
#include <editline/readline.h>
#endif
#endif

void prompt(int argc, char** argv) {
    puts(lang_name_string_builder(" Version 0.0.0.0.1"));
    puts("Press Ctrl+c to Exit\n");

    prepareMOL();

    while (1) {
        /* Now in either case readline will be correctly defined */
        char* input = readline(lang_name_string_builder("> "));
        add_history(input);

        stdin_parser(input);

        free(input);
    }

    clearMOL();
}
