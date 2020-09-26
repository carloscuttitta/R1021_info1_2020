CC=gcc
CFLAGS= -Wall

default: all

chat_server: chat_server.c
	$(CC) $(CFLAGS) -o $@ chat_server.c

chat_client: chat_client.c
	$(CC) $(CFLAGS) -o $@ chat_client.c

clean:
	rm -f chat_server
	rm -f chat_client

all: clean chat_server chat_client

