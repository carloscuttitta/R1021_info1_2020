/* main.c */
#include <unistd.h>
#include <stdio.h>
#include "sensores.h"

int main(int ac, char **av){
	sensor_t *sens = NULL;
	int c;
	
	if ((c=verifica_argumentos(ac, av)) != 0)
		return c;
	
	sens = inicializa_sensores(sens, ac, av);
	while(1){
		lee_sensores(sens);
		imprime_sensores(sens);
		
		printf("----ordenado x id ascendente\n");
		ordenar_sensores(sens, ORDENAR_X_ID, ORDENAR_ASC);
		imprime_sensores(sens);
		printf("----ordenado x id descendente\n");
		ordenar_sensores(sens, ORDENAR_X_ID, ORDENAR_DESC);
		imprime_sensores(sens);
		printf("----ordenado x temp ascendente\n");
		ordenar_sensores(sens, ORDENAR_X_TEMP, ORDENAR_ASC);
		imprime_sensores(sens);
		printf("----ordenado x temp descendente\n");
		ordenar_sensores(sens, ORDENAR_X_TEMP, ORDENAR_DESC);
		imprime_sensores(sens);
		
		imprime_maxt(calcula_maxt(sens));
		imprime_mint(calcula_mint(sens));
		imprime_promedio(calcula_promedio(sens));
		sleep(PERIODO);
		printf("-------------------------\n");
	}

	return 0;
}
