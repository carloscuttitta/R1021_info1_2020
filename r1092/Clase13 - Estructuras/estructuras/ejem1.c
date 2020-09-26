#include <stdio.h>

// definicion de las estructuras

// definicion usando estructura con nombre
struct punto {
                int x;
                int y;
             };

// definicion usando typedef para declarar un nuevo tipo de dato
typedef struct {
                int x;
                int y;
               } spunto_t;


// prototipos
void imprime_punto(spunto_t p);
spunto_t crea_punto(int x, int y);

// main
int main(void){
    struct punto p1;        // declaro una estructura sin inicializar
    spunto_t p2 = {4, 23};  // declaro una estructura usando el tipo definido con typedef
                            // y la inicializo
    spunto_t p3;

    // vefifico cual es el tamanio de la estructura
    printf("el tamanio de la estructura es de %ld bytes\n", sizeof(p1));

    // incializo una estructura, inicializando cada uno de sus miembros
    p1.x = 8;
    p1.y = 12;

    // imprimo los miembros de la estructura
    printf("x=%d, y=%d\n", p1.x, p1.y);

    // imprimo los miembros de una estructura usando una funcion
    // a la que se le pasa la estructura
    imprime_punto(p2);

    // inicializo una estructura mediante una funcion que devuelve una estructura
    p3 = crea_punto(45, 67);
    imprime_punto(p3);

    return 0;
}

// -----------------------------------------------------------------------
void imprime_punto(spunto_t p){
    printf("x=%d, y=%d\n", p.x, p.y);
}

// -----------------------------------------------------------------------
spunto_t crea_punto(int x, int y){
    spunto_t p;
    p.x = x;
    p.y = y;
    return p;
}

