CC=gcc
CFLAGS=-Wall -Wextra -ggdb -std=c99
OBJ=png2c

all install: $(wildcard *.c)
	$(CC) $(CFLAGS) png2c.c -lm -o $(OBJ)
