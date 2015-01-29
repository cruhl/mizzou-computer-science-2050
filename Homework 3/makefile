all = eval 
CC = gcc
CFLAGS = -g -Wall

$(all): runner.o stack.o calculator.o
	$(CC) runner.o stack.o calculator.o $(CFLAGS) -o $@

runner.o: runner.c calculator.h
	$(CC) runner.c $(CFLAGS) -c -o $@

stack.o: stack.c stack.h
	$(CC) stack.c $(CFLAGS) -c -o $@

calculator.o: calculator.c calculator.h stack.h
	$(CC) calculator.c $(CFLAGS) -c -o $@

clean: 
	rm *.o $(all)