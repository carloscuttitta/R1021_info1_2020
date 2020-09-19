CC=gcc
CFLAGS= -Wall
LIBS=../../lib/info1-sockets.c

default: all

server: echo_stream_server.c
	$(CC) $(CFLAGS) -o $@ echo_stream_server.c $(LIBS)

client: echo_stream_client.c
	$(CC) $(CFLAGS) -o $@ echo_stream_client.c $(LIBS)

clean:
	rm -f server
	rm -f client

all: clean server client

