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

# build static library
static: lib$(LIBNAME).a

lib$(LIBNAME).a: $(OBJS)
	ar rcs lib$(LIBNAME).a $(OBJS)
	ranlib lib$(LIBNAME).a

# build dynamic (shared) library
dynamic: lib$(LIBNAME).so

lib$(LIBNAME).so: $(OBJS)
	$(CC) -shared -Wl,-soname,lib$(LIBNAME).so -o lib$(LIBNAME).so $(OBJS)

clean:
	rm -f ../obj/*.o lib$(LIBNAME).a lib$(LIBNAME).so

