/* main.c */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "sensores.h"

sensor_t *sens = NULL;

// -----------------------------------------------------------------------------
void maneja_multiple(int sig){
    switch(sig){
        case SIGUSR1:
            printf("\nEntra SIGUSER1\nChau!\n");
            exit(sig);
            break;
        case SIGUSR2:
            printf("\nEntra SIGUSER2\nMe quedo\n");
            break;
        case SIGKILL:
            exit(sig);
            break;
        default:
            break;
    }
}

// -----------------------------------------------------------------------------
void maneja_alarma(int sig){
    printf("PID: %d\n", getpid());
    lee_sensores(sens);
    imprime_sensores(sens);
    imprime_maxt(calcula_maxt(sens));
    imprime_mint(calcula_mint(sens));
    imprime_promedio(calcula_promedio(sens));
    printf("-------------------------\n");
    alarm(PERIODO);
}

// -----------------------------------------------------------------------------
int main(int ac, char **av){
	int c;
	if ((c=verifica_argumentos(ac, av)) != 0)
		return c;
	
	sens = inicializa_sensores(sens, ac, av);

    // deshabilita el Control-c
    signal(SIGINT, SIG_IGN);
    
    // instala el handler que maneja USR1
    signal(SIGUSR1, maneja_multiple);
    // instala el handler que maneja USR2
    signal(SIGUSR2, maneja_multiple);
    // instala el handler que maneja KILL
    signal(SIGKILL, maneja_multiple);

    // deshabilita el SIGALRM
    signal(SIGALRM, SIG_IGN);
    // instala el handler que maneja KILL
    signal(SIGALRM, maneja_alarma);
    // dispara el timer
    alarm(PERIODO);

	while(1){
		sleep(0.5);
	}

	return 0;
}
