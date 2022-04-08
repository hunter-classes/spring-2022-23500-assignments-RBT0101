OBJECTS=Main.o Labyrinth.o MazeGenerator.o
CXXFLAGS= -g
LDFLAGS= 
CXX=g++

main: $(OBJECTS)
	$(CXX) -g  -o main $(OBJECTS)
Main.o: Main.cpp MazeGenerator.h Labyrinth.h
	g++ -std=c++11 -g -c Main.cpp
Labyrinth.o: Labyrinth.cpp Labyrinth.h
	g++ -std=c++11 -g -c Labyrinth.cpp
MazeGenerator.o: MazeGenerator.cpp MazeGenerator.h Labyrinth.h
	g++ -std=c++11 -g -c MazeGenerator.cpp

clean:
	rm -f $(OBJECTS)
