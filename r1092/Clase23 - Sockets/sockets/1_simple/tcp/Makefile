CC=gcc
CFLAGS= -Wall

default: all

server: simple_stream_server.c
	$(CC) $(CFLAGS) -o $@ simple_stream_server.c

client: simple_stream_client.c
	$(CC) $(CFLAGS) -o $@ simple_stream_client.c

clean:
	rm -f server
	rm -f client

all: clean server client

