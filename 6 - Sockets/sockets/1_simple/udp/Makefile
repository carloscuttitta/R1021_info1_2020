CC=gcc
CFLAGS= -Wall

default: all

server: simple_dgram_server.c
	$(CC) $(CFLAGS) -o $@ simple_dgram_server.c

client: simple_dgram_client.c
	$(CC) $(CFLAGS) -o $@ simple_dgram_client.c

clean:
	rm -f server
	rm -f client

all: clean server client

