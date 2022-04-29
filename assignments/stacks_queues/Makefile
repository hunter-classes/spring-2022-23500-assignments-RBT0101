tests: tests.o Node.o Stack.o Queue.o
	g++ -std=c++11 -o tests tests.o Node.o Stack.o Queue.o

main: main.o Node.o Stack.o Queue.o
	g++ -std=c++11 -o main main.o Node.o Stack.o Queue.o

main.o: main.cpp Node.h Stack.h
	g++ -std=c++11 -c main.cpp
	
tests.o: tests.cpp Node.h Stack.h
	g++ -std=c++11 -c tests.cpp
	
Queue.o: Queue.cpp 
	g++ -std=c++11 -c Queue.cpp
	
Node.o: Node.cpp
	g++ -std=c++11 -c Node.cpp
	
Stack.o: Stack.cpp Node.h
	g++ -std=c++11 -c Stack.cpp

clean:
	rm -f *.o main tests

