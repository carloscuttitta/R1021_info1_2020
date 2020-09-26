all:
	gcc -c -g -Wall -o main.o main.c
	gcc -c -g -Wall -o pubsub.o pubsub.c
	gcc -c -g -Wall -o backend.o backend.c
	gcc -g -Wall -o main main.o pubsub.o backend.o

clean:
	rm -f *.o main