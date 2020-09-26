#include <stdio.h>

int main(void){
    char *pc;
    int *pi;
    double *pd;

    printf("el tamanio de 'pc' es %ld y el de lo apuntando es %ld\n", sizeof(pc), sizeof(*pc));
    printf("el tamanio de 'pi' es %ld y el de lo apuntando es %ld\n", sizeof(pi), sizeof(*pi));
    printf("el tamanio de 'pd' es %ld y el de lo apuntando es %ld\n", sizeof(pd), sizeof(*pd));

    return 0;
}
