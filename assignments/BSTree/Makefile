main: main.o BSTree.o Node.o
	g++ -std=c++11 -o main main.o BSTree.o Node.o
tests:  tests.o BSTree.o Node.o
	g++ -std=c++11 -o tests tests.o BSTree.o Node.o
BSTree.o: BSTree.cpp Node.h BSTree.h
	g++ -std=c++11 -c BSTree.cpp
main.o: main.cpp Node.h BSTree.h
	g++ -std=c++11 -c main.cpp
tests.o: tests.cpp Node.h BSTree.h
	g++ -std=c++11 -c  tests.cpp
Node.o: Node.cpp Node.h
	g++ -std=c++11 -c Node.cpp
clean:
	rm -f *.o main tests
