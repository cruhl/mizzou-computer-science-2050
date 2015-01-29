# Header: 
#	Conner Ruhl
#	ID: 14226013
#	10/07/2014
#	Lab Section C
#	Code: Jace, the Mind Sculpter


all: minesweeper
	
minesweeper: runner.o minesweeper.o 
	gcc runner.o minesweeper.o -o minesweeper

runner.o: runner.c minesweeper.h
	gcc runner.c -c

minesweeper.o: minesweeper.c minesweeper.h
	gcc minesweeper.c -c

clean:
	rm *.o minesweeper