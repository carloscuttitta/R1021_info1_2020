#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
/* Estado de los procesos
D 	Uninterruptible sleep (usualmente IO)
R 	Ejecutándose(running) o en cola de ejecución
S 	Interruptible sleep (p.e. esperando un evento)
T 	Detenido
Z 	Proceso zombie
*/
int main(void){
	int	i, a=0;
	
	for(i=0; i<5; i++) {
		if(!fork()) {
			a++;
			printf("Proceso hijo #%d: Proceso padre #%d: %d, a=%d\n", i, getpid(),getppid (), a);
			sleep(10);
			printf("Proceso hijo #%d terminando\n", i);
			exit(0);
		}
	}
	
	printf("Padre terminando\n");
			sleep(30);
	wait(NULL); // probar sin wait
	
	return 0;
}
