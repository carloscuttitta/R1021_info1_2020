#include <stdio.h>

int main(void){
    double d;
    printf("ingrese un numero en punto flotante: ");
    scanf("%lf", &d);
    // AVISO !!!
    // si cuando compilas salta un error en la asignacion del valor que retorna sizeof()
    // cambiar %d a %ld
    // esto es porque en arquitecturas de 32 bits sizeof() devuelve un int
    // y en arquitecturas de 64 bits devuelve un long
    printf("el tamanio del numero es %d bytes y el valor es %f\n", sizeof(d), d);
    return 0;
}
