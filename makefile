CC 	= gcc
SRC 	= ./src
CSTD 	= -std=c99
CFLAGS 	= $(CSTD) -I$(SRC) -Wall
DFLAGS = -g -Wno-stack-protector
OUTPUT 	= .
LIBDIR 	= ./lib
LIB_MPC = $(LIBDIR)/mpc.c
FILES	= $(wildcard $(SRC)/*.c)

ifneq ($(OS),Windows_NT)
	CFLAGS += -ledit -lm
endif

.PHONY: prompt debug clean

prompt: $(FILES)
	$(CC) $(CFLAGS) $^ $(LIB_MPC) -o $(OUTPUT)/$@

debug: $(FILES)
	$(CC) $(DFLAGS) $(CFLAGS) $^ $(LIB_MPC) -o $(OUTPUT)/$@

clean: $(OUTPUT)/prompt* $(OUTPUT)/debug*
	rm -f $^
