#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void){
	int	i, a=0;
	
	for(i=0; i<50; i++) {
		if(!fork()) {
			a++;
			printf("Proceso hijo #%d: %d, a=%d\n", i, getpid(), a);
			exit(0);
		}
	}
	
	wait(NULL);
	
	return 0;
}
