CC=gcc
CFLAGS=-Wall
LDFLAGS=­
OBJS=readtextpos.o 
SOURCES=$(OBJS:.o=.c)
HEADERS=*.h

readtextpos: $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c Makefile $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f ./*.o
	rm -f readtextpos

all: clean readtextpos

