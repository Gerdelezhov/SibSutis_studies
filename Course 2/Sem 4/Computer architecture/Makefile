CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

SRCDIR = src
OBJDIR = obj
LIBDIR = lib
BINDIR = bin

LIBNAME = libmysimplecomputer.a

SRC = $(wildcard $(SRCDIR)/lib/*.c)
OBJ = $(patsubst $(SRCDIR)/lib/%.c,$(OBJDIR)/%.o,$(SRC))

MAIN = $(SRCDIR)/main/main.c
APP = $(BINDIR)/app

all: $(APP)

$(APP): $(MAIN) $(LIBDIR)/$(LIBNAME)
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $< -L$(LIBDIR) -lmysimplecomputer -o $@

$(OBJDIR)/%.o: $(SRCDIR)/lib/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBDIR)/$(LIBNAME): $(OBJ)
	mkdir -p $(LIBDIR)
	ar rcs $@ $^

clean:
	rm -rf $(OBJDIR)
	rm -rf $(LIBDIR)
	rm -rf $(BINDIR)
