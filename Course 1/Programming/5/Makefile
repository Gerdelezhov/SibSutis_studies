all: main

main: obj/main.o obj/strings.o
	gcc -Wall -Werror -I strings obj/main.o obj/strings.o -o bin/main -g -O2

obj/main.o: main.c
	gcc -Wall -Werror -I strings -c main.c -o obj/main.o -g

obj/strings.o: strings/strings.c
	gcc -Wall -Werror -I strings -c strings/strings.c -o  obj/strings.o -g

.PHONY: clean

clean:
	rm main *.o strings/*.o
