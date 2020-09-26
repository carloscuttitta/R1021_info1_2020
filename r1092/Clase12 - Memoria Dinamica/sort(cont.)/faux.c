#include <stdio.h>      // para printf
#include <stdlib.h>     // para rand

// devuelve un entero entre min y max
int get_rand(int min, int max){
    return rand()%(max-min)+min;
}

// llena un array de longitud len con numeros aleatorios
void fill_array(int *p, int len, int min, int max){
    int i;
    for(i=0; i<len; i++){
        *p = get_rand(min, max);
        p++;
    }
}

// llena un array de longitud len con numeros aleatorios (float)
void fill_array_float(float *p, int len, int min, int max){
    int i;
    for(i=0; i<len; i++){
        *p = (float)get_rand(min*100, max*100) / 100.0;
        p++;
    }
}

// imprime un array de longitud len
void print_array(int *p, int len){
    int i;
    for(i=0; i<len; i++){
        printf("%d ", *p);
        p++;
    }
    printf("\n");
}

// imprime un array de longitud len (float)
void print_array_float(float *p, int len){
    int i;
    for(i=0; i<len; i++){
        printf("%5.2f ", *p);
        p++;
    }
    printf("\n");
}

