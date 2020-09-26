CC=gcc
CFLAGS=-c
LDFLAGS=­
OBJS=test.o lista_doble.o
SOURCES=$(OBJS:.o=.c)
HEADERS=*.h

test: $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c Makefile $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f ./*.o
	rm -f test

all: clean test

