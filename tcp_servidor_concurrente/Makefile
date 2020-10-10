CC=gcc
CFLAGS= -Wall

default: all

eco_server: eco_server.c
	$(CC) $(CFLAGS) -o $@ eco_server_fork.c

echo_client: echo_client.c
	$(CC) $(CFLAGS) -o $@ echo_client.c

clean:
	rm -f eco_server_fork
	rm -f echo_client

all: clean eco_server_fork echo_client

