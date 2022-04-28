main: main.o Node.o BSTree.o
	g++ -std=c++11 -o main main.o Node.o BSTree.o
	
main.o: BStree.h 
	g++ -std=c++11 -c main.cpp
	
Node.o: Node.h
	g++ -std=c++11 -c Node.cpp
	
BSTree.o: BSTree.h
	g++ -std=c++11 -c BSTree.cpp
	
clean:
	rm -f main main.o Node.o BSTree.o
