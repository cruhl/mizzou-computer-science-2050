# Header: 
#	Conner Ruhl
#	ID: 14226013
#	10/28/2014
#	Lab Section C
#	Code: Hookah

all: LinkedListProgram
	
LinkedListProgram: runner.o queue.o 
	gcc runner.o queue.o -o LinkedListProgram

runner.o: runner.c queue.h
	gcc runner.c -c

queue.o: queue.c queue.h
	gcc queue.c -c

clean:
	rm *.o LinkedListProgram