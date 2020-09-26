/*
** pipe3.c -- un ejemplo de pipe un poco mas inteligente
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void){
	int pfds[2];
	char buf[30] = {0};

	if (pipe(pfds) == -1){
		perror("error en pipe");
		exit(1);
	}

	if (!fork()){
		printf(" HIJO %d: escribiendo en el pipe\n", getpid());
		write(pfds[1], "prueba", 6);
		printf(" HIJO %d: terminando\n", getpid());
		exit(0);
	} 
	else{
		printf("PADRE %d: leyendo desde el pipe\n", getpid());
		read(pfds[0], buf, 6);
		printf("PADRE %d: leido \"%s\"\n", getpid(), buf);
		wait(NULL);
	}

	close(pfds[0]);
	close(pfds[1]);
	return 0;
}

