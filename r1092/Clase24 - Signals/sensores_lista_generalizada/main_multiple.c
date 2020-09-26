/* main.c */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "sensores.h"

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
        case SIGABRT:
            printf("\nAbortando ...\n");
            fflush(stdout);
            exit(sig);
            break;
        default:
            break;
    }
}

// -----------------------------------------------------------------------------
int main(int ac, char **av){
    sensor_t *sens = NULL;
	int c;
	if ((c=verifica_argumentos(ac, av)) != 0)
		return c;
	
	sens = inicializa_sensores(sens, ac, av);

    // deshabilita el Control-c
    signal(SIGINT, SIG_IGN);
    
    // instala el handler que maneja SIGUSR1
    signal(SIGUSR1, maneja_multiple);
    // instala el handler que maneja SIGUSR2
    signal(SIGUSR2, maneja_multiple);
    // instala el handler que maneja SIGABRT
    signal(SIGABRT, maneja_multiple);


	while(1){
        printf("PID: %d\n", getpid());
		lee_sensores(sens);
		imprime_sensores(sens);
		imprime_maxt(calcula_maxt(sens));
		imprime_mint(calcula_mint(sens));
		imprime_promedio(calcula_promedio(sens));
		sleep(PERIODO);
		printf("-------------------------\n");
	}

	return 0;
}
