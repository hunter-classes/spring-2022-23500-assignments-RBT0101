main: main.o Node.o Person.o Dictionary.o Linked_List.o
	g++ -std=c++11 -o main main.o Node.o Person.o Dictionary.o Linked_List.o
tests:  tests.o Node.o Person.o Dictionary.o Linked_List.o
	g++ -std=c++11 -o tests tests.o Node.o Person.o Dictionary.o Linked_List.o
main.o: main.cpp Node.h Person.h Dictionary.h Linked_List.h
	g++ -std=c++11 -c main.cpp
tests.o: tests.cpp Node.h Person.h Dictionary.h Linked_List.h
	g++ -std=c++11 -c  tests.cpp
Linked_List.o: Linked_List.cpp Node.h Person.h
	g++ -std=c++11 -c Linked_List.cpp 
Dictionary.o: Dictionary.cpp Node.h Person.h Linked_List.h
	g++ -std=c++11 -c Dictionary.cpp
Person.o: Person.cpp Person.h
	g++ -std=c++11 -c Person.cpp
Node.o: Node.cpp Node.h Person.h
	g++ -std=c++11 -c Node.cpp
clean:
	rm -f *.o main tests
