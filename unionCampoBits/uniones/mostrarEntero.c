#include <stdio.h>

typedef	unsigned char        int8_t;

union enteros {
    int     numero;
    int8_t  byteEntero[4];
};

int main (void)
{
    int datoEntero;
    uint8_t *p;
    union enteros numeroEntero;

    p=(uint8_t*)&datoEntero;
//-- Ingreso de datos --
    printf("Ingrese valor : ");
    scanf("%d", &datoEntero);
    numeroEntero.numero = datoEntero;
  //-- Impresión de datos --
    printf("el dato en numeroEntero.numero  :\t%d\n",numeroEntero.numero);  
    printf("address memory en datoEntero    :\t%p\n",&datoEntero);
    printf("---------------------------------\n");
    printf("dato en *(p+1) :\t%02x\t el dato en byte_0 es  :\t%02x\n",*(p+0),numeroEntero.byteEntero[0]);
    printf("dato en *(p+1) :\t%02x\t el dato en byte_1 es  :\t%02x\n",*(p+1),numeroEntero.byteEntero[1]);
    printf("dato en *(p+2) :\t%02x\t el dato en byte_2 es  :\t%02x\n",*(p+2),numeroEntero.byteEntero[2]);
    printf("dato en *(p+3) :\t%02x\t el dato en byte_3 es  :\t%02x\n",*(p+3),numeroEntero.byteEntero[3]);
  return (0);
}
