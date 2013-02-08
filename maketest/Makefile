CC=gcc
CFLAGS=-o
OBJFLAGS=-c

test:test.o testpart1.o testpart2.o
	$(CC) $(CFLAGS) $@ test.o testpart1.o testpart2.o
testpart1.o:testpart1.c
	$(CC) $(OBJFLAGS) testpart1.c
testpart2.o:testpart2.c
	$(CC) $(OBJFLAGS) testpart2.c
test.o:test.c
	$(CC) $(OBJFLAGS) test.c
clean:
	rm test
	rm testpart1.o
	rm testpart2.o

