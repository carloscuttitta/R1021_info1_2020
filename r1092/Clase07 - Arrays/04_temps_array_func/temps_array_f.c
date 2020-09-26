#include <stdio.h>
#include "func_temps.h"

int main(void){
	int t[CANT_TEMPS];
	float prom;

	// ingreso de datos	
	ingreso(t);
		
	// imprime temperaturas
	imprime(t);
		
	// calcula promedio
	prom = calcula_promedio(t);
	
	// imprime promedio
	printf("tprom = %.2f\n", prom);

	return 0;
}


