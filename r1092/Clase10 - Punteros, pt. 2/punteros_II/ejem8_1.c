#include <stdio.h>

#define SIZE 3

// prototipos
void print_variables(int **p);

int main(void){
    int t0, t1, t2; // declaro las variables
    int *a[SIZE+1]; // declaro un array de punteros a enteros

    a[0] = &t0;     // asigno a cada puntero del array la direccion de una variable
    a[1] = &t1;
    a[2] = &t2;
    a[3] = NULL;    // para indicar que el array termino, le asigno un puntero NULO => valor 0

    t0 = 23;        // incializo las variables
    t1 = 45;
    t2 = 12;

    print_variables(a);

    t0 += 10;       // modifico de alguna forma las variables
    t1 -= 5;
    t2++;

    print_variables(a);

    return 0;
}

//imprime las variables
void print_variables(int **p){ // es lo mismo que declarar (int *p[])

    while(*p != NULL){  // es lo mismo que hacer while(*p)
        printf("%d ", **p);
        p++;
    }
    putchar('\n');
}
