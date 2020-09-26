/*
** pipe2.c -- otro ejemplo estupido de pipe
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#define LEN 9

void escribir(int, char *);
void leer(int);

void escribir(int wr, char * s) {
	printf("escribiendo en el file descriptor #%d\n", wr);
	write(wr, s, LEN);
}

void leer(int rd) {
	char buf[30] = {0};
	printf("leyendo desde el file descriptor #%d\n", rd);
	read(rd, buf, LEN);
	printf("leido \"%s\"\n", buf);
}


int main(void){
	int pfds[2];

	if (pipe(pfds) == -1){
		perror("error en pipe");
		exit(1);
	}

	escribir(pfds[1], "Prueba#1");
	leer(pfds[0]);
	escribir(pfds[1], "Prueba#2");
	escribir(pfds[1], "Prueba#3");
	leer(pfds[0]);
	leer(pfds[0]);

	close(pfds[0]);
	close(pfds[1]);
	return 0;
}

