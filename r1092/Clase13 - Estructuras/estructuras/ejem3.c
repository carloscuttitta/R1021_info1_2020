#include <stdio.h>

// definicion de las estructuras
typedef struct {
                int x;
                int y;
               } spunto_t;
typedef struct {
                spunto_t p1;
                spunto_t p2;
               } srectangulo_t;

// prototipos
void imprime_rectangulo (srectangulo_t *r);


// main
int main(void){

    // declaro un rectangulo e inicializo los puntos
    srectangulo_t rect1 = { {2, 5}, {7, 10} }; 
    srectangulo_t rect2;
    srectangulo_t rect3;

    spunto_t punto1 = {23, 45};
    spunto_t punto2 = {67, 98};

    // imprimo rectangulo usando un puntero
    imprime_rectangulo(&rect1);

    // inicializo un rectangulo inicializando cada uno de los miembros 
    rect2.p1.x = 44;
    rect2.p1.y = 12;
    rect2.p2.x = 55;
    rect2.p2.y = 88;
    imprime_rectangulo(&rect2);

    // inicializo un rectangulo con los puntos creados anteriormente
    rect3.p1 = punto1;
    rect3.p2 = punto2;
    imprime_rectangulo(&rect3);

    return 0;
}

// -------------------------------------------------------------------
void imprime_rectangulo(srectangulo_t *r){
    printf("(%d, %d), (%d, %d)\n", r->p1.x, r->p1.y, r->p2.x, r->p2.y);
}
