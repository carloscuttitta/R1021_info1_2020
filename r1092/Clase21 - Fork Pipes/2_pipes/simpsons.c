/*
** simpsons.c -- ejemplo de comunicación transgeneracional
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define CANT 10

void padre(char *, int, char *, int);
void hijo(char *, int);

void padre(char * h1, int fd1, char * h2, int fd2) {
	int i, d1, d2;
	int r1=0, r2=0;
	
	for(i=0;i<CANT;i++) {
		read(fd1, &d1, sizeof(d1));
		read(fd2, &d2, sizeof(d2));
		printf("En turno #%d, %s dice %d, %s dice %d\n", i+1, h1, d1, h2, d2);
		
		if(d1>d2) {
			r1++;
		}
		else if (d1<d2) {
			r2++;
		}
		else {
			// Empate
		}
	}
	
	printf("Puntaje Final: %s = %d || %s = %d\n", h1, r1, h2, r2);
}

void hijo(char * n, int fd) {
	int i,d;
	srandom((int)getpid());
	for(i=0;i<CANT;i++) {
		sleep(1); // probar sin sleep
		d = random()%10+1;
		printf("\t%s [PID:%d] dice turno #%d : %d\n", n, getpid(), i+1, d);
		write(fd, &d, sizeof(d));
	}
}

int main(void){

	int p_bart[2];
	int p_lisa[2];
	
	pipe(p_bart);
	pipe(p_lisa);
	
	if(!fork()) {
		hijo("Bart", p_bart[1]);
		exit(0);
	}
	else if(!fork()) {
		hijo("Lisa", p_lisa[1]);
		exit(0);
	}
	else {
		padre("Bart", p_bart[0], "Lisa", p_lisa[0]);
		wait(NULL);
	}
	

	close(p_bart[0]);
	close(p_bart[1]);
	close(p_lisa[0]);
	close(p_lisa[1]);

	return 0;
}
