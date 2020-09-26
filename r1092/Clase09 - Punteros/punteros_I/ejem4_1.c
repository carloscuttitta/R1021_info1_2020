#include <stdio.h>

#define SIZE 10

int main(void){
    int a[SIZE];
    int *p;
    int aux;

    // lleno el array usando subindice
    for(aux=0; aux<SIZE; aux++)
        a[aux] = aux*2;

    // lo imprimo usando un puntero
    p = a;
    for(aux=0; aux<SIZE; aux++)
        printf("%d ", *(p+aux));
    putchar('\n');

    return 0;
}
