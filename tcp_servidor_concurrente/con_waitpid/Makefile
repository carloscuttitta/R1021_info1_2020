CC=gcc
CFLAGS= -Wall

default: all

eco_server_wait: eco_server_wait.c
	$(CC) $(CFLAGS) -o $@ eco_server_fork_wait.c

echo_client_wait: echo_client_wait.c
	$(CC) $(CFLAGS) -o $@ echo_client_wait.c

clean:
	rm -f eco_server_fork_wait
	rm -f echo_client_wait

all: clean eco_server_fork_wait echo_client_wait

