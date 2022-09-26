CFLAGS = -Wall

coder: main.o coder.o command.o
		$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
		$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

coder.o: coder.c
		$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

command.o: command.c
		$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<
