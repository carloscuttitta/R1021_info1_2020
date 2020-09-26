#include <stdio.h>

int main(void){
    char c;
    printf("ingrese un caracter: ");
    scanf("%c", &c);
    // AVISO !!!
    // si cuando compilas salta un error en la asignacion del valor que retorna sizeof()
    // cambiar %d a %ld
    // esto es porque en arquitecturas de 32 bits sizeof() devuelve un int
    // y en arquitecturas de 64 bits devuelve un long
    printf("el tamanio del caracter es %d bytes, el valor es %d 0x%02x 0%03o y el caracter es '%c'\n", sizeof(c), c, c, c, c);
    return 0;
}
