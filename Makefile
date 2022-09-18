CC := gcc
CFLAGS := -Iinclude -Wall -Wextra -std=c99 -O3


override CFILES := $(shell find ./ -type f -name '*.c')
override OFILES := $(shell find ./ -type f -name '*.o')

all: clean compl
clean:
	rm -rf obj/ bin/

compl:
	mkdir -p obj/ bin/
	$(foreach file, $(CFILES), $(CC) $(CFLAGS) -c $(file) -o obj/$(basename $(notdir $(file))).o;)

	gcc $(OFILES) -o bin/compl