#include <stdio.h>
#include <math.h>

int main(void) {
    int x, y;
    int cuad;
    double dist;

    printf("Ingrese coordenadas: ");
    scanf("%d %d", &x, &y);

    if(x>0 && y>0){
    	cuad = 1;
    }
    else if(x<0 && y>0){
    	cuad = 2;
    }
    else if(x<0 && y<0){
    	cuad = 3;
    }
    else if(x>0 && y<0){
        cuad = 4;
    }
    else{
    	cuad = 0;
    }

    //----------------------------
    if(cuad == 0){
        printf("Error! la coordenada x=%d, y=%d no pertenece a ningun cuadrante\n", x, y);
    }
    else{
    	dist = sqrt(pow((double)x, 2.0) + pow((double)y, 2.0));

    	printf("El cuadrante es %d\n", cuad);
    	printf("La distancia es %.2f\n", dist);
    }
    return 0;
}

