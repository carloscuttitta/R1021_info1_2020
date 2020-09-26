#include <stdio.h>

#define CANT_TEMPS 5

void ingreso(int temp[]);
void imprime(int temp[]);
float calcula_promedio(int temp[]);

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

