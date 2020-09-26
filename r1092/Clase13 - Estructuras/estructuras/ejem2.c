#include <stdio.h>

// definicion de las estructuras
typedef struct {
                int x;
                int y;
               } spunto_t;


// prototipos
void imprime_punto(spunto_t *p);
spunto_t *crea_punto(spunto_t *p, int x, int y);

// main
int main(void){
    spunto_t p1 = {4, 23};  // declaro una estructura usando el tipo definido con typedef
                            // y la inicializo
    spunto_t *pp1;
    spunto_t p2, *pp2;

    // inicializo el puntero a la estructura
    pp1 = &p1;

    // imprimo los miembros de la estructura usando la estructura
    printf("x=%d, y=%d\n", p1.x, p1.y);

    // imprimo los miembros de la estructura usando el puntero a la estructura
    printf("x=%d, y=%d\n", (*pp1).x, (*pp1).y);

    // pero, como la construccion (*pp1). es tan comun se reemplaza por la sintaxis pp1->
    printf("x=%d, y=%d\n", pp1->x, pp1->y);

    // inicializo una estructura pasandole un puntero.
    // Como ejemplo adicional la funcion devuelve un puntero a la estructura inicializada
    pp2 = crea_punto(&p2, 26, 69);

    // imprime los miembros de la estructura usando el puntero
    imprime_punto(pp2);

    return 0;
}

// -------------------------------------------------------------------
void imprime_punto(spunto_t *p){
    printf("x=%d, y=%d\n", p->x, p->y);
}

// -------------------------------------------------------------------
spunto_t *crea_punto(spunto_t *p, int x, int y){
    p->x = x;
    p->y = y;
    return p;
}
