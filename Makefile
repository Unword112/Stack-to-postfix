all: LinkedList.o main.o ChainNode.o LinkedStack.o
	g++ LinkedList.o main.o ChainNode.o LinkedStack.o -o Linked

ChainNode.o: ChainNode.cpp
	g++ -c ChainNode.cpp -o ChainNode.o 

LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp -o LinkedList.o  

main.o: main.cpp
	g++ -c main.cpp -o main.o 

LinkedStack.o: LinkedStack.cpp
	g++ -c LinkedStack.cpp -o LinkedStack.o 

clean:
	rm -f *.o Linked