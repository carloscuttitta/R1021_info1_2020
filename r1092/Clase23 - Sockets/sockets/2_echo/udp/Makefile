CC=gcc
CFLAGS= -Wall

default: all

server: echo_dgram_server.c
	$(CC) $(CFLAGS) -o $@ echo_dgram_server.c

client: echo_dgram_client.c
	$(CC) $(CFLAGS) -o $@ echo_dgram_client.c

clean:
	rm -f server
	rm -f client

all: clean server client

