#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void){
	int	i, a=0, x;
	
	for(i=0; i<5; i++) {
		if((x=fork())==0) {
			a++;
			printf("Proceso hijo #%d: %d, a=%d\n", i, getpid(), a);
			sleep(10);
			printf("Proceso hijo #%d terminando\n", i);
			exit(0);
		}
		printf("Creando hijo #%d\n",x);
	}
	
	printf("Padre terminando\n");
	//wait(NULL); // probar sin wait
	
	return 0;
}
