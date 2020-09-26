#include <stdlib.h> // para srand
#include <time.h>   // para time
#include "faux.h"

#define MIN 1
#define MAX 100
#define SIZE 10

// prototipos
void bubble_sort(int *p, int len);
void swap(int *p, int *q);

int main(void){
    int a[SIZE];

    srand((int)time(NULL));
    fill_array(a, SIZE, MIN, MAX);
    print_array(a, SIZE);
    bubble_sort(a, SIZE);
    print_array(a, SIZE);

    return 0;
}

// ordena un array de menor a mayor usando el algoritmo bubble sort
void bubble_sort(int *p, int len){
    int i, j;
    for(i=0; i<len-1; i++)
        for(j=i+1; j<len; j++)
            if(p[i] > p[j])
		        swap(&p[i], &p[j]);
}

// intercambia los valores apuntados por ambos punteros
void swap(int *p, int *q){
    int aux;
    aux = *p;
    *p = *q;
    *q = aux;
}

