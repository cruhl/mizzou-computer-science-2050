# Header: 
#	Conner Ruhl
#	ID: 14226013
#	11/4/2014
#	Lab Section C
#	Code: Euphonium

all: bst
	
bst: runner.o bst.o 
	gcc runner.o bst.o -o bst

runner.o: runner.c bst.h
	gcc runner.c -c

bst.o: bst.c bst.h
	gcc bst.c -c

clean:
	rm *.o bst