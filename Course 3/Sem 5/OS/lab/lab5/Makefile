CC = gcc

CFLAGS = -Wall -g

SRC = student.c list.c
OBJ = $(SRC:.c=.o)

TARGET = main

LIBNAME = libstudents.so

$(TARGET): $(LIBNAME) main.o
	gcc -o main main.c -L. -lstudents -Wl,-rpath=.

$(LIBNAME): $(OBJ)
	gcc -shared -o libstudents.so $(OBJ)

$(OBJ):
	$(CC) -c -fPIC $(SRC)

clean:
	rm -f *.so
	rm -f *.o 
	rm -f *.dat
	rm -f main
.PHONY: clean

all: $(TARGET)
