# lib/Makefile
CC = gcc
CFLAGS = -I../include -Wall -g -fPIC
SRCS = ../src/mystrfunctions.c ../src/myfilefunctions.c
OBJS = $(SRCS:../src/%.c=../obj/%.o)
LIBNAME = myutils

.PHONY: all static dynamic clean

all: static dynamic

../obj/%.o: ../src/%.c
	mkdir -p ../obj
	$(CC) $(CFLAGS) -c $< -o $@

static: lib/lib$(LIBNAME).a

lib/lib$(LIBNAME).a: $(OBJS)
	mkdir -p lib
	ar rcs lib/lib$(LIBNAME).a $(OBJS)
	ranlib lib/lib$(LIBNAME).a

dynamic: lib/lib$(LIBNAME).so

lib/lib$(LIBNAME).so: $(OBJS)
	mkdir -p lib
	$(CC) -shared -Wl,-soname,lib$(LIBNAME).so -o lib/lib$(LIBNAME).so $(OBJS)

clean:
	rm -f ../obj/*.o lib/*.a lib/*.so

