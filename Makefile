CC=gcc
CFLAGS=-Wall -Wextra -ggdb -std=c99
OBJ=png2c

all install: png2c.c
	$(CC) $(CFLAGS) png2c.c -lm -o $(OBJ)
