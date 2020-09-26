CC=gcc
CFLAGS=-c
LDFLAGS=­
OBJS=calc.o calc-func.o
SOURCES=$(OBJS:.o=.c)
HEADERS=*.h

calc: $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c Makefile $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f ./*.o
	rm -f calc

all: clean calc

