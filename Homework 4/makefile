all = tree 
CC = gcc
CFLAGS = -g -Wall

$(all): runner.o print.o list.o tree.o
	$(CC) runner.o print.o list.o tree.o $(CFLAGS) -o $@

runner.o: runner.c list.o
	$(CC) runner.c $(CFLAGS) -c -o $@

print.o: print.c print.h list.o
	$(CC) print.c $(CFLAGS) -c -o $@

list.o: list.c list.h tree.o
	$(CC) list.c $(CFLAGS) -c -o $@

tree.o: tree.c tree.h
	$(CC) tree.c $(CFLAGS) -c -o $@

clean: 
	rm *.o $(all)