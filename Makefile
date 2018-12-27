CC=g++
CFLAGS= -std=c++11 -pedantic -Wall -Wextra -g

sudoku: sudoku.o subsections.o board.o
	$(CC) -o sudoku sudoku.o subsections.o board.o

sudoku.o: sudoku.cpp board.h
	$(CC) $(CFLAGS) -c sudoku.cpp board.cpp

subsections.o: subsections.cpp subsections.h
	$(CC) $(CFLAGS) -c subsections.cpp

board.o: board.cpp board.h subsections.h
	$(CC) $(CFLAGS) -c board.cpp subsections.cpp



clean:
	rm -f *.o *.gch sudoku
