CC=gcc
CFLAGS= -Wall

default: all

eco_server: eco_server.c
	$(CC) $(CFLAGS) -o $@ eco_server_fork.c

eco_client: eco_client.c
	$(CC) $(CFLAGS) -o $@ eco_client.c

clean:
	rm -f eco_server_fork
	rm -f eco_client

all: clean eco_server_fork eco_client

