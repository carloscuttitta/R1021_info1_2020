#include <stdio.h>

int cuadrante(int x, int y);
double calcular_distancia(double x, double y);

int main(void) {
	
	int xxx,yyy;
	int rescuad;
	double dist;
	
	while(1) {
		printf("Ingrese coordenadas: ");
		scanf("%d %d", &xxx, &yyy);
		
		// Cortar el ciclo infinito
		if(!xxx && !yyy) {
			break;
		}
		rescuad = cuadrante(xxx, yyy);
		dist = calcular_distancia((double)xxx, (double)yyy);
		printf("El cuadrante es %d y la distancia %.2f\n", rescuad, dist);
	}	
	return 0;		
}


