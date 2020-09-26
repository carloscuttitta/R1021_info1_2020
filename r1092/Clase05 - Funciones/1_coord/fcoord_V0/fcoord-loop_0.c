#include <stdio.h>
#include <math.h>

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

int cuadrante(int x, int y){
	int cuad;
	if(x>0 && y>0) {
		cuad=1;
	}
	else if(x<0 && y>0) {
		cuad=2;
	}
	else if(x<0 && y<0) {
		cuad=3;
	}
	else if(x>0 && y<0) {
		cuad=4;
	}
	return cuad;
}

double calcular_distancia(double x, double y){
	return sqrt(pow(x, 2.0) + pow(y, 2.0));
}

