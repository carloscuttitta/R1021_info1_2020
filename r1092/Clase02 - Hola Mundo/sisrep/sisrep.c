#include <stdio.h>

int main(void){
    int a;
    printf("ingrese numero: ");	// ingreso el numero
    scanf("%d", &a);
    /*
    voy a imprimir en los
    distintos formatos
    */

    printf("a (decimal) = %d\n", a);
    printf("a (octal)   = 0%o\n", a);
    printf("a (hexa)    = 0x%04x\n", a);
    return 0;
}
