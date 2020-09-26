CC=gcc
CFLAGS=-c
LDFLAGS=­
OBJS=main.o sensores.o
SOURCES=$(OBJS:.o=.c)
HEADERS=*.h

sens: $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c Makefile $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f ./*.o
	rm -f sens

all: clean sens

