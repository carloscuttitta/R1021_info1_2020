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
    for(aux=0, p=a; aux<SIZE; aux++, p++){
        printf("%d ", *p);
    }
    putchar('\n');

    return 0;
}
