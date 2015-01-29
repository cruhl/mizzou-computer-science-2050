all: bst
	
bst: runner.o bst.o 
	gcc runner.o bst.o -o bst

runner.o: runner.c bst.h
	gcc runner.c -c

bst.o: bst.c bst.h
	gcc bst.c -c

clean:
	rm *.o bst