# Header: 
#	Conner Ruhl
#	ID: 14226013
#	10/07/2014
#	Lab Section C
#	Code: Rick and Marty

all: LinkedListProgram
	
LinkedListProgram: runner.o list.o 
	gcc runner.o list.o -o LinkedListProgram

runner.o: runner.c list.h
	gcc runner.c -c

list.o: list.c list.h
	gcc list.c -c

clean:
	rm *.o LinkedListProgram