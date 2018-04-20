CC = gcc
CFLAGS = -Wall -pedantic -std=C99 -c
OUTNAME = rechner

compile: rechner.o clean
	$(CC) -o $(OUTNAME) rechner.o
rechner.o: rechner.c
	$(CC) $(CFLAGS) rechner.c
clean:
	rm -f *.o