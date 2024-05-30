CC = gcc
CFLAGS = -Wall -g
LIBS = -ldl

TARGET = app

all: $(TARGET)

$(TARGET): main7.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f $(TARGET)
