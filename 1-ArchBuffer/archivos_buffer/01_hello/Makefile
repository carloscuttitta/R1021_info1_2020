CC=gcc
CFLAGS=-Wall
LDFLAGS=
OBJS=hello.o
SOURCES=$(OBJS:.o=.c)
HEADERS=*.h

hello: $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c Makefile $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f ./*.o
	rm -f hello
	rm -f hello.txt

all: clean hello

