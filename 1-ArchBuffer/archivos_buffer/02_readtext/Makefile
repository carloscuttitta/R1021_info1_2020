CC=gcc
CFLAGS=-Wall
LDFLAGS=­
OBJS=readtext.o 
SOURCES=$(OBJS:.o=.c)
HEADERS=*.h

readtext: $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c Makefile $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f ./*.o
	rm -f readtext

all: clean readtext

