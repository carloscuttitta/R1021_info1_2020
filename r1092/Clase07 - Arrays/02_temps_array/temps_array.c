#include <stdio.h>

#define CANT_TEMPS 5

int main(void){
	int t[CANT_TEMPS];
	int i;
	float prom = 0.0;

	// ingreso de datos	
	for (i=0; i<CANT_TEMPS; i++){
		printf("temp %d? ", i+1);
		scanf("%d", &t[i]);
	}
	
	// imprime temperaturas
	printf("temps ");
	for (i=0; i<CANT_TEMPS; i++)
		printf("%d ", t[i]);
	printf("\n");
	
	// calcula promedio
	for (i=0; i<CANT_TEMPS; i++)
		prom += (float)t[i];
	prom /= CANT_TEMPS;

	// imprime promedio
	printf("tprom = %.2f\n", prom);

	return 0;
}
