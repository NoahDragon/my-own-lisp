CC=gcc
SRC=./src
CSTD=-std=c99
CFLAGS=$(CSTD) -I$(SRC) -Wall
OUTPUT=.
LIBDIR=./lib
LIB_MPC=$(LIBDIR)/mpc.c

prompt: $(SRC)/prompt.c
	$(CC) $(CFLAGS) $^ $(LIB_MPC) -lm -o $(OUTPUT)/$@ 

clean:
	rm -f $(OUTPUT)/prompt*
