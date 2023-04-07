CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

SRCDIR = src
OBJDIR = obj
LIBDIR = lib
BINDIR = bin

LIB1 = libmysimplecomputer.a
LIB2 = libmyterm.a
LIBNAME = $(LIB1) $(LIB2)

MAIN = $(SRCDIR)/main/main.c
APP = $(BINDIR)/main

TESTAPPMAIN1 = $(SRCDIR)/main/test_libmysimplecomputer.c
TESTAPP1 = $(BINDIR)/test_mysimplecomputer

TESTAPPMAIN2 = $(SRCDIR)/main/test_libmyterm.c
TESTAPP2 = $(BINDIR)/test_myterm

all: DIR $(TESTAPP1) $(TESTAPP2) $(APP)

# основной исполняемый файл
$(APP):
	$(CC) $(CFLAGS) $(MAIN) -L$(LIBDIR) -lmysimplecomputer -lmyterm -o $@

# тестовый исполняемый файл для myterm
$(TESTAPP2): $(TESTAPPMAIN2) $(LIBDIR)/$(LIB2)
	$(CC) $(CFLAGS) $< -L$(LIBDIR) -lmyterm -o $@

$(LIBDIR)/$(LIB2): $(OBJDIR)/myterm.o
	ar rcs $@ $^

$(OBJDIR)/myterm.o: $(SRCDIR)/lib/myterm.c
	$(CC) $(CFLAGS) -c $< -o $@

# тестовый исполняемый файл для mysiplecomputer
$(TESTAPP1): $(TESTAPPMAIN1) $(LIBDIR)/$(LIB1)
	$(CC) $(CFLAGS) $< -L$(LIBDIR) -lmysimplecomputer -o $@

$(LIBDIR)/$(LIB1): $(OBJDIR)/mysimplecomputer.o
	ar rcs $@ $^

$(OBJDIR)/mysimplecomputer.o: $(SRCDIR)/lib/mysimplecomputer.c
	$(CC) $(CFLAGS) -c $< -o $@

DIR:
	mkdir -p $(OBJDIR)
	mkdir -p $(LIBDIR)
	mkdir -p $(BINDIR)

.PHONY: clean
clean:
	rm -rf $(OBJDIR)
	rm -rf $(LIBDIR)
	rm -rf $(BINDIR)
