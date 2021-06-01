CC			?= gcc

ifdef OS 
	MINGCC  ?= gcc
else
	MINGCC  ?= x86_64-w64-mingw32-gcc
endif

CFLAGS		?=-Wall -Wextra -ggdb -std=c99
OBJ			?=png2c

all install: debug

debug: linux

release: linux windows
	
linux: $(wildcard *.c)
	$(CC) $(CFLAGS) png2c.c -lm -o $(OBJ)

windows: $(wildcard *.c)
	$(MINGCC) $(CFLAGS) png2c.c -lm -o $(OBJ)
