CC=gcc
CFLAGS=-Wall
LDFLAGS=­
OBJS=libros.o 
SOURCES=$(OBJS:.o=.c)
HEADERS=*.h

fifos:
	$(CC) $(CFLAGS) -o gen gen.c
	$(CC) $(CFLAGS) -o filter filter.c
	$(CC) $(CFLAGS) -o fifero fifero.c

clean:
	rm -f gen
	rm -f filter
	rm -f fifero

all: clean fifos

