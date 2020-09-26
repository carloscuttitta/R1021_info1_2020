CC=gcc
CFLAGS=-Wall
LDFLAGS=­
OBJS=libros.o 
SOURCES=$(OBJS:.o=.c)
HEADERS=*.h

libros: $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c Makefile $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f ./*.o
	rm -f libros

all: clean libros

