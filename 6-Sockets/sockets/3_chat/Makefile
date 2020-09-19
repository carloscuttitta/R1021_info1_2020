CC=gcc
CFLAGS= -Wall
LIBS=info1-sockets.c

default: all

chat_server: chat_server.c
	$(CC) $(CFLAGS) -o $@ chat_server.c $(LIBS)

chat_client: chat_client.c
	$(CC) $(CFLAGS) -o $@ chat_client.c $(LIBS)

clean:
	rm -f chat_server
	rm -f chat_client

all: clean chat_server chat_client

