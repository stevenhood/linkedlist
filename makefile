all: linkedlist
#	g++ Main.cpp Node.cpp LinkedList.cpp -o linkedlist

linkedlist: Main.o Node.o LinkedList.o
	g++ Main.o Node.o LinkedList.o -o linkedlist

Main.o: Main.cpp
	g++ -c Main.cpp

Node.o: Node.cpp
	g++ -c Node.cpp

LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp

clean:
	rm *.o linkedlist
