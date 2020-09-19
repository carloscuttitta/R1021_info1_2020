CC=gcc
CFLAGS= -Wall
LIBS=../../lib/info1-sockets.c

default: all

server: simple_dgram_server.c
	$(CC) $(CFLAGS) -o $@ simple_dgram_server.c $(LIBS)

client: simple_dgram_client.c
	$(CC) $(CFLAGS) -o $@ simple_dgram_client.c $(LIBS)

clean:
	rm -f server
	rm -f client

all: clean server client

