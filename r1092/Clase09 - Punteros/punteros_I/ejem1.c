#include <stdio.h>

int main(void){
    int i;
    int *pi;

    i = 2;
    pi = &i;

    printf("la direccion de 'i' es %p y su contenido %d\n", &i, i);
    printf("la direccion de 'pi' es %p y su contenido %p\n", &pi, pi);
    printf("el contenido de lo apuntado por 'pi' es %d\n", *pi);

    return 0;
}
