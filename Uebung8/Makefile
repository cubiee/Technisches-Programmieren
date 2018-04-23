CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -c
PROGNAME = fileanalyse

compile: main.o
	$(CC) -o $(PROGNAME) main.o 
main.o: main.c
	$(CC) $(CFLAGS) main.c