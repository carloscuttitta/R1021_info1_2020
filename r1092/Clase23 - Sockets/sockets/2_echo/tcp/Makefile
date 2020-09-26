CC=gcc
CFLAGS= -Wall

default: all

server: echo_stream_server.c
	$(CC) $(CFLAGS) -o $@ echo_stream_server.c

client: echo_stream_client.c
	$(CC) $(CFLAGS) -o $@ echo_stream_client.c

clean:
	rm -f server
	rm -f client

all: clean server client

