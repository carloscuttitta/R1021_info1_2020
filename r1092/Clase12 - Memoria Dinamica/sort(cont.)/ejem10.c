#include <stdlib.h> // para srand
#include <time.h>   // para time
#include <stdio.h>
#include "faux.h"

#define MIN 1
#define MAX 100
#define SIZE 10

// prototipos
void bubble_sort(void *p, int len, int size, int (*fcomp)(void *x, void *y), void (*fswap)(void *m, void *n));
void swap_enteros(void *p, void *q);
int comp_ascendente_enteros(void *x, void *y);
int comp_descendente_enteros(void *x, void *y);
void swap_floats(void *p, void *q);
int comp_ascendente_floats(void *x, void *y);
int comp_descendente_floats(void *x, void *y);

int main(void){
    int a[SIZE];
    float b[SIZE];

    srand((int)time(NULL));
    printf("--------------- int\n");
    fill_array(a, SIZE, MIN, MAX);
    print_array(a, SIZE);
    bubble_sort(a, SIZE, sizeof(int), comp_ascendente_enteros, swap_enteros);
    print_array(a, SIZE);
    bubble_sort(a, SIZE, sizeof(int), comp_descendente_enteros, swap_enteros);
    print_array(a, SIZE);

    printf("--------------- float\n");
    fill_array_float(b, SIZE, MIN, MAX);
    print_array_float(b, SIZE);
    bubble_sort(b, SIZE, sizeof(float), comp_ascendente_floats, swap_floats);
    print_array_float(b, SIZE);
    bubble_sort(b, SIZE, sizeof(float), comp_descendente_floats, swap_floats);
    print_array_float(b, SIZE);

    return 0;
}

// ordena un array usando el algoritmo bubble sort 
// usando fcomp para comparar y fswap para permutar
void bubble_sort(void *p, int len, int size, int (*fcomp)(void *x, void *y), void (*fswap)(void *m, void *n)){
    int i, j;
    for(i=0; i<(len*size)-size; i+=size)
        for(j=i+size; j<len*size; j+=size)
	    if(fcomp(p+i, p+j))
		fswap(p+i, p+j);
}

// intercambia los valores apuntados por ambos punteros
void swap_enteros(void *p, void *q){
    int aux;
    aux = *(int*)p;
    *(int*)p = *(int*)q;
    *(int*)q = aux;
}

// compara para ordenar en forma ascendente
int comp_ascendente_enteros(void *x, void *y){
    return *(int*)x > *(int*)y;
}

// compara para ordenar en forma descendente
int comp_descendente_enteros(void *x, void *y){
    return *(int*)x < *(int*)y;
}

// intercambia los valores apuntados por ambos punteros (float)
void swap_floats(void *p, void *q){
    float aux;
    aux = *(float*)p;
    *(float*)p = *(float*)q;
    *(float*)q = aux;
}

// compara para ordenar en forma ascendente (float)
int comp_ascendente_floats(void *x, void *y){
    return *(float*)x > *(float*)y;
}

// compara para ordenar en forma descendente (float)
int comp_descendente_floats(void *x, void *y){
    return *(float*)x < *(float*)y;
}

