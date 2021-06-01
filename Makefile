CC			?= gcc

ifdef OS 
	MINGCC  ?= gcc
else
	MINGCC  ?= x86_64-w64-mingw32-gcc
endif

CFLAGS		?= -Wall -Wextra -ggdb -std=c99
OBJ			?= bin/png2c

all install: debug

debug: linux

release: linux windows
	
linux: $(wildcard src/*.c) $(wildcard src/*.h)
	$(CC) $(CFLAGS) src/main.c -lm -o $(OBJ)

windows: $(wildcard src/*.c) $(wildcard src/*.h)
	$(MINGCC) $(CFLAGS) src/main.c -lm -o $(OBJ)
