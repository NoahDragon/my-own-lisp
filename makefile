CC 	= gcc
SRC 	= ./src
CSTD 	= -std=c99
CFLAGS 	= $(CSTD) -I$(SRC) -Wall
OUTPUT 	= .
LIBDIR 	= ./lib
LIB_MPC = $(LIBDIR)/mpc.c

ifneq ($(OS),Windows_NT)
	CFLAGS += -ledit -lm
endif

prompt: $(SRC)/main.c $(SRC)/utils.c $(SRC)/parsing.c $(SRC)/prompt.c
	$(CC) $(CFLAGS) $^ $(LIB_MPC) -o $(OUTPUT)/$@ 

debug: $(SRC)/main.c $(SRC)/utils.c $(SRC)/parsing.c $(SRC)/prompt.c
	$(CC) -g $(CFLAGS) $^ $(LIB_MPC) -o $(OUTPUT)/$@ 

clean: $(OUTPUT)/prompt* $(OUTPUT)/debug*
	rm -f $^
