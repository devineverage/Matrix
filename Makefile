all: PriorityTest

Matrix: Matrix.o p1.o
	g++ -o Matrix Matrix.o p1.o
 
Matrix.o: p1.cpp Matrix.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c p1.cpp
 
clean:
	rm -rf main
	rm -rf *.o