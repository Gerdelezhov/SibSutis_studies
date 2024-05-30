CC = g++
CFLAGS = -Wall

SRC_FILES = server.cpp client.cpp
EXECUTABLES = $(SRC_FILES:.cpp=)

all: $(EXECUTABLES)

%: %.cpp
	clang-format -style="{BasedOnStyle: Google, IndentWidth: 4}" -i $<
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLES)