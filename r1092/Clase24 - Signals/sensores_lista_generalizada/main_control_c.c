/* main.c */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "sensores.h"

// -----------------------------------------------------------------------------
void maneja_control_c(int sig){
    printf("\nEntra Control-C\nChau!\n");
    exit(sig);
}

// -----------------------------------------------------------------------------
int main(int ac, char **av){
	sensor_t *sens = NULL;
	int c;
	if ((c=verifica_argumentos(ac, av)) != 0)
		return c;
	
	sens = inicializa_sensores(sens, ac, av);

    // instala el handler que maneja Control-c
    signal(SIGINT, maneja_control_c);

	while(1){
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
