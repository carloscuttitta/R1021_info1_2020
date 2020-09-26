#include <stdlib.h> // para srand
#include <time.h>   // para time
#include "faux.h"

#define MIN 1
#define MAX 100
#define SIZE 10

// prototipos
void bubble_sort(int *p, int len, int (*fcomp)(int x, int y), void (*fswap)(int *m, int *n));
void swap(int *p, int *q);
int comp_ascendente(int x, int y);
int comp_descendente(int x, int y);

int main(void){
    int a[SIZE];

    srand((int)time(NULL));
    fill_array(a, SIZE, MIN, MAX);
    print_array(a, SIZE);
    bubble_sort(a, SIZE, comp_ascendente, swap);
    print_array(a, SIZE);
    bubble_sort(a, SIZE, comp_descendente, swap);
    print_array(a, SIZE);

    return 0;
}

// ordena un array usando el algoritmo bubble sort 
// usando fcomp para comparar y fswap para permutar
void bubble_sort(int *p, int len, int (*fcomp)(int x, int y), void (*fswap)(int *m, int *n)){
    int i, j;
    for(i=0; i<len-1; i++)
        for(j=i+1; j<len; j++)
	        if(fcomp(p[i], p[j]))
		        fswap(&p[i], &p[j]);
}

// intercambia los valores apuntados por ambos punteros
void swap(int *p, int *q){
    int aux;
    aux = *p;
    *p = *q;
    *q = aux;
}

// compara para ordenar en forma ascendente
int comp_ascendente(int x, int y){
    return x > y;
}

// compara para ordenar en forma descendente
int comp_descendente(int x, int y){
    return x < y;
}

