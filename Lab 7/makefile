# Header: 
#	Conner Ruhl
#	ID: 14226013
#	10/21/2014
#	Lab Section C
#	Code: Charizard

all: LinkedListProgram
	
LinkedListProgram: runner.o set.o 
	gcc runner.o set.o -o LinkedListProgram

runner.o: runner.c set.h
	gcc runner.c -c

set.o: set.c set.h
	gcc set.c -c

clean:
	rm *.o LinkedListProgram