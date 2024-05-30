CXX = g++

CXXFLAGS =

TARGET = main

OBJS = main.o fraction.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp fraction.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

fraction.o: fraction.cpp fraction.hpp
	$(CXX) $(CXXFLAGS) -c fraction.cpp

clean:
	rm -f $(TARGET) $(OBJS)

run: $(TARGET)
	./$(TARGET)
