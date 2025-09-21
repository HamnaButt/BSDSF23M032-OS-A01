# lib/Makefile
CC = gcc
CFLAGS = -I../include -Wall -g -fPIC
SRCS = ../src/mystrfunctions.c ../src/myfilefunctions.c
OBJS = $(SRCS:../src/%.c=../obj/%.o)
LIBNAME = myutils

.PHONY: all static clean

all: static

../obj/%.o: ../src/%.c
	mkdir -p ../obj
	$(CC) $(CFLAGS) -c $< -o $@

static: lib$(LIBNAME).a

lib$(LIBNAME).a: $(OBJS)
	ar rcs lib$(LIBNAME).a $(OBJS)
	ranlib lib$(LIBNAME).a

clean:
	rm -f ../obj/*.o lib$(LIBNAME).a

