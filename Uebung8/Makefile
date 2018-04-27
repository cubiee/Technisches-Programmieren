CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -c
PROGNAME = geheim

all: compile clean

compile: geheim.o
	$(CC) -o $(PROGNAME) geheim.o 
geheim.o: geheim.c
	$(CC) $(CFLAGS) geheim.c
clean: 
	rm -f *.o
