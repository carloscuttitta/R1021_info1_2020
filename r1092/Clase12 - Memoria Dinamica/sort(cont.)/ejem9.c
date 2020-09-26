#include <stdlib.h> // para srand
#include <time.h>   // para time
#include "faux.h"

#define MIN 1
#define MAX 100
#define SIZE 10

// prototipos
void bubble_sort(int *p, int len, int (*fcomp)(void *x, void *y), void (*fswap)(void *m, void *n));
void swap_enteros(void *p, void *q);
int comp_ascendente_enteros(void *x, void *y);
int comp_descendente_enteros(void *x, void *y);

int main(void){
    int a[SIZE];

    srand((int)time(NULL));
    fill_array(a, SIZE, MIN, MAX);
    print_array(a, SIZE);
    bubble_sort(a, SIZE, comp_ascendente_enteros, swap_enteros);
    print_array(a, SIZE);
    bubble_sort(a, SIZE, comp_descendente_enteros, swap_enteros);
    print_array(a, SIZE);

    return 0;
}

// ordena un array usando el algoritmo bubble sort 
// usando fcomp para comparar y fswap para permutar
void bubble_sort(int *p, int len, int (*fcomp)(void *x, void *y), void (*fswap)(void *m, void *n)){
    int i, j;
    for(i=0; i<len-1; i++)
        for(j=i+1; j<len; j++)
	        if(fcomp(&p[i], &p[j]))
		        fswap(&p[i], &p[j]);
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

