#include <stdio.h>
#include <time.h>
#include "funciones.h"

int main(int argc, char ** argv) {
    int c;
    nodo_t * n = NULL;
    
    n = ingresar(n);
    // Tengo todo cargado
    
    c = contar_mediciones(n,argv[1]);

    printf("Unidad: %s\n", argv[1]);
    printf("Cantidad: %d\n", c);  
    
    if(!c) {
        perror("No tengo mediciones para la unidad dada");
        return 1;
    }
    
    
    printf("Maximo: %.9f %s\n", calcular_maximo(n,argv[1]), argv[1]);  
    printf("Minimo: %.9f %s\n", calcular_minimo(n,argv[1]), argv[1]);
    printf("Promedio: %.9f %s\n", calcular_promedio(n,argv[1]), argv[1]);
    
    imprimir_primeros(n, 10, argv[1]);
    
    liberar_mediciones(n);
    
    return 0;
}
