#include <stdio.h>
#include <time.h>
#include "funciones.h"

int main(int argc, char ** argv) {
    medicion_t * m[MAX];
    int c;
    
    ingresar(m);
    // Tengo todo cargado
    
    c = contar_mediciones(m,argv[1]);

    printf("Unidad: %s\n", argv[1]);
    printf("Cantidad: %d\n", c);  
    
    if(!c) {
        perror("No tengo mediciones para la unidad dada");
        return 1;
    }
    
    printf("Maximo: %.9f %s\n", calcular_maximo(m,argv[1]), argv[1]);  
    printf("Minimo: %.9f %s\n", calcular_minimo(m,argv[1]), argv[1]);
    printf("Promedio: %.9f %s\n", calcular_promedio(m,argv[1]), argv[1]);
    
    ordenar_mediciones(m);
    
    imprimir_primeros(m, 10, argv[1]);
    
    liberar_mediciones(m);
    
    return 0;
}
