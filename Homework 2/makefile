all: TheProgram
TheProgram: runner.o lib.o 
	gcc runner.o lib.o -o TheProgram

runner.o: runner.c lib.h
	gcc runner.c -c

lib.o: lib.c lib.h
	gcc lib.c -c
clean:
	rm *.o TheProgram