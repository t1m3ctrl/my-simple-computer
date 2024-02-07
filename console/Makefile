СС=gcc
CFLAGS=-c -Wall

all: test

hello: test.o
	$(CC) test.o -o test

test.o: test.c
	$(CC) $(CFLAGS) test.c

clean:
	rm -rf *.o test