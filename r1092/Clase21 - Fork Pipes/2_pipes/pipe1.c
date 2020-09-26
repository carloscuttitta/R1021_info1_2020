/*
** pipe1.c -- un ejemplo estupido de pipe
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(void){
	int pfds[2];
	char buf[30] = {0};

	if (pipe(pfds) == -1){
		perror("error en pipe");
		exit(1);
	}

	printf("escribiendo en el file descriptor #%d\n", pfds[1]);
	write(pfds[1], "prueba", 6);
	printf("leyendo desde el file descriptor #%d\n", pfds[0]);
	read(pfds[0], buf, 6);
	printf("leido \"%s\"\n", buf);
	
	close(pfds[0]);
	close(pfds[1]);
	return 0;
}

