CC=gcc
CFLAGS=-o
OBJFLAGS=-c

test:time2.o
	$(CC) $(CFLAGS) $@ time2.o

time2.o:time2.c
	$(CC) $(OBJFLAGS) time2.c
clean:
	rm test
	rm time2.o

