main: main.o Node.o List.o
	g++ -std=c++11 -o main main.o Node.o List.o

test: test.o Node.o List.o
	g++ -std=c++11 -o test test.o Node.o List.o

main.o: main.cpp Node.h List.h
	g++ -std=c++11 -c main.cpp

test.o: test.cpp Node.h List.h doctest.h
	g++ --std=c++11 -c test.cpp

Node.o: Node.cpp Node.h
	g++ -std=c++11 -c Node.cpp

List.o: List.cpp List.h
	g++ -std=c++11 -c List.cpp

clean: 
	rm -f main test main.o test.o Node.o List.o
