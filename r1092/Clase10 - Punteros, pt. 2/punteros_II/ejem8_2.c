#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SIZE 3
#define MINTEMP -10
#define MAXTEMP  50

// prototipos
int get_temp(void);
void print_temps(int **p);
int max_temp(int **p);
int min_temp(int **p);
float prom_tempw(int **p);
float prom_tempf(int **p);
int get_rand(int min, int max);

//--------------------------------
int main(void){
    int t0, t1, t2; // declaro las variables
    int *a[SIZE+1]; // declaro un array de punteros a enteros

    a[0] = &t0;     // asigno a cada puntero del array la direccion de una variable
    a[1] = &t1;
    a[2] = &t2;
    a[3] = NULL;    // para indicar que el array termino, le asigno un puntero NULO => valor 0

    srand((int)time(NULL));

    while(1){
        t0 = get_temp();    // obtiene la temperatura de cada sensor
        t1 = get_temp();
        t2 = get_temp();
        print_temps(a);
        printf("min=%d\tmax=%d\tprom=%.2f\t%.2f\n", min_temp(a), max_temp(a), prom_tempw(a), prom_tempf(a));

        sleep(1);
    }
    return 0;
}


// devuelve un entero entre min y max
int get_rand(int min, int max){
    return rand()%(max-min)+min;
}

// lee la temperatura de un sensor (simulado con get_rand)
int get_temp(void){
    return get_rand(MINTEMP, MAXTEMP);
}

//imprime las temperaturas
void print_temps(int **p){ // es lo mismo que declarar (int *p[])
    while(*p != NULL){  // es lo mismo que hacer while(*p)
        printf("%d\t", **p);
        p++;
    }
}

// devuelve la maxima temperatura
int max_temp(int **p){
    int max = MINTEMP;
    while(*p){
        if (**p > max)
            max = **p;
        p++;
    }
    return max;
}

// devuelve la temperatura minima
int min_temp(int **p){
    int min = MAXTEMP;
    while(*p){
        if (**p < min)
            min = **p;
        p++;
    }
    return min;
}

// calcula el promedio de temperaturas (version con while)
float prom_tempw(int **p){
    int suma=0, n=0;
    while(*p){
        suma += **p;
        n++;
        p++;
    }
    return (float)suma / n;
}

// calcula el promedio de temperaturas (version con for)
float prom_tempf(int **p){
    int suma, n;
    for(suma=0, n=0; *p; n++, p++)
        suma += **p;
    return (float)suma / n;
}

