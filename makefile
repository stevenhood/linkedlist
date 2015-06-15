# Courtesy of Mrbook (http://mrbook.org/blog/tutorials/make/)

CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Main.cpp Node.cpp LinkedList.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=linkedlist

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o linkedlist
