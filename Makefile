CC := gcc
CFLAGS := -Iinc -Wall -Wextra -std=c99 -O3 -lraylib -lm -g

all: clean compl
clean:
	rm -rf bin/

compl:
	mkdir -p bin/
	gcc src/compl.c $(CFLAGS) -o bin/compl

run: ./bin/compl
	$^