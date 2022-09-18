CC := gcc
CFLAGS := -Iinclude -Wall -Wextra -std=c99 -O3 -lraylib -lm

all: clean compl
clean:
	rm -rf bin/

compl:
	mkdir -p bin/
	gcc src/compl.c $(CFLAGS) -o bin/compl