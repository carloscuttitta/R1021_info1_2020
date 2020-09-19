#include <stdio.h>

typedef	unsigned char        uint8_t;

union flotante {
    float    numero;
    uint8_t   byteFlotante[4];
};

int main (void)
{
    float datoFloat;
    uint8_t *p;
    union flotante numeroFlotante;

    p=(uint8_t*)&datoFloat;
//-- Ingreso de datos --
    printf("Ingrese valor : ");
    scanf("%f", &datoFloat);
    numeroFlotante.numero = datoFloat;
  //-- Impresión de datos --
    printf("el dato en numeroFlotante.numero  :\t%f\n",numeroFlotante.numero);  
    printf("address memory en datoFloat    :\t%p\n",&datoFloat);
    printf("---------------------------------\n");
    printf("dato en *(p+0) :\t%02x\t el dato en byte_0 es  :\t%02x\n",*(p+0),numeroFlotante.byteFlotante[0]);
    printf("dato en *(p+1) :\t%02x\t el dato en byte_1 es  :\t%02x\n",*(p+1),numeroFlotante.byteFlotante[1]);
    printf("dato en *(p+2) :\t%02x\t el dato en byte_2 es  :\t%02x\n",*(p+2),numeroFlotante.byteFlotante[2]);
    printf("dato en *(p+3) :\t%02x\t el dato en byte_3 es  :\t%02x\n",*(p+3),numeroFlotante.byteFlotante[3]);
  return (0);
}
