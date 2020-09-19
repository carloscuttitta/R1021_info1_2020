#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 256

typedef struct {
    long    legajo;
    char    apellido[31];
}datos_t;

int imprimir_nombres(datos_t **);
