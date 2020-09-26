#include <stdlib.h> // para srand
#include <time.h>   // para time
#include <stdlib.h> // para malloc
#include <string.h> // para memcpy
#include <stdio.h>
#include "faux.h"

#define MIN 1
#define MAX 100
#define SIZE 10

// prototipos
void bubble_sort(void *p, int len, int size, 
                 int (*fcomp)(void *x, void *y), 
                 void (*fswap)(void *m, void *n, int size));
void swap(void *p, void *q, int size);
int comp_ascendente_enteros(void *x, void *y);
int comp_descendente_enteros(void *x, void *y);
int comp_ascendente_floats(void *x, void *y);
int comp_descendente_floats(void *x, void *y);

int main(void){
    int a[SIZE];
    float b[SIZE];

    srand((int)time(NULL));
    printf("--------------- int\n");
    fill_array(a, SIZE, MIN, MAX);
    print_array(a, SIZE);
    bubble_sort(a, SIZE, sizeof(int), comp_ascendente_enteros, swap);
    print_array(a, SIZE);
    bubble_sort(a, SIZE, sizeof(int), comp_descendente_enteros, swap);
    print_array(a, SIZE);

    printf("--------------- float\n");
    fill_array_float(b, SIZE, MIN, MAX);
    print_array_float(b, SIZE);
    bubble_sort(b, SIZE, sizeof(float), comp_ascendente_floats, swap);
    print_array_float(b, SIZE);
    bubble_sort(b, SIZE, sizeof(float), comp_descendente_floats, swap);
    print_array_float(b, SIZE);

    return 0;
}

// ordena un array usando el algoritmo bubble sort 
// usando fcomp para comparar y fswap para permutar
void bubble_sort(void *p, int len, int size,
                 int (*fcomp)(void *x, void *y),
                 void (*fswap)(void *m, void *n, int size)){
    int i, j;
    for(i=0; i<(len*size)-size; i+=size)
        for(j=i+size; j<len*size; j+=size)
	    if(fcomp(p+i, p+j))
		fswap(p+i, p+j, size);
}

// intercambia los valores apuntados por ambos punteros
// version usando memoria dinamica
void swap(void *p, void *q, int size){
    void *aux;
    aux = malloc(size);
    memcpy(aux, p, size);
    memcpy(p, q, size);
    memcpy(q, aux, size);
    free(aux);
}

// compara para ordenar en forma ascendente
int comp_ascendente_enteros(void *x, void *y){
    return *(int*)x > *(int*)y;
}

// compara para ordenar en forma descendente
int comp_descendente_enteros(void *x, void *y){
    return *(int*)x < *(int*)y;
}

// compara para ordenar en forma ascendente (float)
int comp_ascendente_floats(void *x, void *y){
    return *(float*)x > *(float*)y;
}

// compara para ordenar en forma descendente (float)
int comp_descendente_floats(void *x, void *y){
    return *(float*)x < *(float*)y;
}

