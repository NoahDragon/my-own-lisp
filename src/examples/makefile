
# .phony is used to avoid command is the same as the file name.
# e.g. in this file we have a make command is doge_code and under
# the folder there is a file also named as doge_code. With the 
# .phone setting, the "make doge_code" will pick up the command
# doge_code we defined in the makefile.
.PHONY: doge_code doge_grammar

doge_code:
	gcc -Wall -std=c99 doge_code.c ../../lib/mpc.c -lm -o exampleDoge
doge_grammar:
	gcc -Wall -std=c99 doge_grammar.c ../../lib/mpc.c -lm -o exampleDogeGrammar 