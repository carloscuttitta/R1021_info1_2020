CC=gcc
CFLAGS=-Wall
LDFLAGS=­
OBJS=scanf-test.o 
SOURCES=$(OBJS:.o=.c)
HEADERS=*.h

scanf-test: $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c Makefile $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f ./*.o
	rm -f scanf-test

all: clean scanf-test

