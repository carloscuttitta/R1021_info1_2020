#include <math.h>

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

