#include <stdlib.h> // para srand
#include <time.h>   // para time
#include "faux.h"

#define MIN 1
#define MAX 100
#define SIZE 10

// prototipos
void bubble_sort(int *p, int len);

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
    int i, j, aux;
    for(i=0; i<len-1; i++){
        for(j=i+1; j<len; j++){
            if(p[i] > p[j]){
		        aux = p[i];
		        p[i] = p[j];
		        p[j] = aux;
	        }
	    }
    }
}


