CC=gcc
CFLAGS=-Wall -Werror -Wextra -Wpedantic -std=c11
OBJ=png2c

all install: png2c.c
	$(CC) $(CFLAGS) png2c.c -lm -o $(OBJ)
