#include <stdio.h>

#define SIZE 3

// prototipos
void print_mensajes(char **p);
void print_mensaje(char *p);
void print_mensaje_index(char **p, int i);

int main(void){
    char *a[SIZE+1]; // declaro un array de punteros a char

    a[0] = "mensaje_0"; // inicializo cada uno de los punteros
    a[1] = "mensaje_1";
    a[2] = "mensaje_2";
    a[3] = NULL;    // para indicar que el array termino, le asigno un puntero NULO => valor 0

    print_mensajes(a);          // imprime todos los mensajes

    print_mensaje(a[1]);        // imprime un solo mensaje

    print_mensaje_index(a, 2);  // imprime un solo mensaje usando el array y un subindice

    return 0;
}

//imprime todos los mensajes
void print_mensajes(char **p){

    while(*p){
        printf("%s\n", *p);
        p++;
    }
}

//imprime un mensaje
void print_mensaje(char *p){
    printf("%s\n", p);
}

// imprime un mensaje usando el array de punteros y un subindice
void print_mensaje_index(char **p, int i){
    printf("%s\n", p[i]);
}


