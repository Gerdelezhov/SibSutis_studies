all: main
	
main: tries.o main.o
	gcc -Wall tries.o main.o -o main -g -O0
tries.o: tries.c
	gcc -Wall -c tries.c -o tries.o -g -O0
main.o: main.c
	gcc -Wall -c main.c -o main.o -g -O0

.PHONY: clean

clean:
	rm main main.o tries.o