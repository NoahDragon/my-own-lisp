CC=gcc
SRC=./src
CFLAGS=-I$(SRC)
OUTPUT=.

# $(OUTPUT)/%.o: $(SRC)/%.c
#	$(CC) -std=c99 -Wall $@ $< $(CFLAGS)

promptmake:
	$(CC) -std=c99 -Wall $(SRC)/prompt.c -o $(OUTPUT)/prompt 

clean:
	rm -f $(OUTPUT)/prompt*
