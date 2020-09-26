#include <stdio.h>
#include "func_temps.h"

// ---------------------------------------------
void ingreso(int temp[]){
	int i;
	for (i=0; i<CANT_TEMPS; i++){
		printf("temp %d? ", i+1);
		scanf("%d", &temp[i]);
	}
}

// ---------------------------------------------
void imprime(int temp[]){
	int i;
	printf("temps ");
	for (i=0; i<CANT_TEMPS; i++)
		printf("%d ", temp[i]);
	printf("\n");
}

// ---------------------------------------------
float calcula_promedio(int temp[]){
	int i;
	float p = 0.0;
	for (i=0; i<CANT_TEMPS; i++)
		p += (float)temp[i];
	p /= CANT_TEMPS;
	return p;
}

