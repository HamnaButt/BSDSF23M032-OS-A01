# src/Makefile
CC = gcc
CFLAGS = -I../include -Wall -g
SRCS = $(wildcard *.c)
OBJS = $(SRCS:%.c=../obj/%.o)
BIN = ../bin
LIB = ../lib
LIBNAME = myutils

.PHONY: multifile static dynamic clean

../obj/%.o: %.c
	mkdir -p ../obj
	$(CC) $(CFLAGS) -c $< -o $@

# direct compilation into a single exe (multifile)
multifile: $(OBJS)
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -o $(BIN)/client $(OBJS)

# link with static library (assumes lib/libmyutils.a exists)
static: ../obj/main.o
	$(MAKE) -C ../lib static
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -o $(BIN)/client_static ../obj/main.o -L$(LIB) -l$(LIBNAME)

# dynamic link (assumes lib/libmyutils.so exists)
dynamic: ../obj/main.o
	$(MAKE) -C ../lib dynamic
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -L$(LIB) -Wl,-rpath=$(CURDIR)/../lib -l$(LIBNAME) -o $(BIN)/client_dynamic ../obj/main.o

clean:
	rm -f ../obj/*.o ../bin/*

