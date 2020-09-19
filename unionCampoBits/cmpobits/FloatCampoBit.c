#include <stdio.h>

typedef	unsigned char        uint8_t;

// LITTLE ENDIAN: Es el que lo hace del menos significativo al más significativo
struct alfa{
    uint8_t f22:1;
    uint8_t f21:1;
    uint8_t f20:1;
    uint8_t f19:1;
    uint8_t f18:1;
    uint8_t f17:1;
    uint8_t f16:1;
    uint8_t f15:1;
    uint8_t f14:1;
    uint8_t f13:1;
    uint8_t f12:1;
    uint8_t f11:1;
    uint8_t f10:1;
    uint8_t f9:1;
    uint8_t f8:1;
    uint8_t f7:1;
    uint8_t f6:1;
    uint8_t f5:1;
    uint8_t f4:1;
    uint8_t f3:1;
    uint8_t f2:1;
    uint8_t f1:1;
    uint8_t f0:1;
    uint8_t e7:1;
    uint8_t e6:1;
    uint8_t e5:1;
    uint8_t e4:1;
    uint8_t e3:1;
    uint8_t e2:1;
    uint8_t e1:1;
    uint8_t e0:1;
    uint8_t s:1;
};

union flotante {
    float    numero;
    uint8_t   byteFlotante[4];
    struct alfa flota;
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
    printf("address memory de datoFloat    :\t%p\n",&datoFloat);
    printf("---------------------------------\n");
    printf("dato en *(p+0) :\t%02x\t el dato en byte_0 es  :\t%02x\n",*(p+0),numeroFlotante.byteFlotante[0]);
    printf("dato en *(p+1) :\t%02x\t el dato en byte_1 es  :\t%02x\n",*(p+1),numeroFlotante.byteFlotante[1]);
    printf("dato en *(p+2) :\t%02x\t el dato en byte_2 es  :\t%02x\n",*(p+2),numeroFlotante.byteFlotante[2]);
    printf("dato en *(p+3) :\t%02x\t el dato en byte_3 es  :\t%02x\n",*(p+3),numeroFlotante.byteFlotante[3]);
    printf("---------------------------------\n");

    printf("%d",numeroFlotante.flota.s);
    printf("%d",numeroFlotante.flota.e7);
    printf("%d",numeroFlotante.flota.e6);
    printf("%d",numeroFlotante.flota.e5);
    printf("%d",numeroFlotante.flota.e4);
    printf("%d",numeroFlotante.flota.e3);
    printf("%d",numeroFlotante.flota.e2);
    printf("%d",numeroFlotante.flota.e1);
    printf("%d",numeroFlotante.flota.e0);
    printf("%d",numeroFlotante.flota.f0);
    printf("%d",numeroFlotante.flota.f1);
    printf("%d",numeroFlotante.flota.f2);
    printf("%d",numeroFlotante.flota.f3);
    printf("%d",numeroFlotante.flota.f4);
    printf("%d",numeroFlotante.flota.f5);
    printf("%d",numeroFlotante.flota.f6);
    printf("%d",numeroFlotante.flota.f7);
    printf("%d",numeroFlotante.flota.f8);
    printf("%d",numeroFlotante.flota.f9);
    printf("%d",numeroFlotante.flota.f10);
    printf("%d",numeroFlotante.flota.f11);
    printf("%d",numeroFlotante.flota.f12);
    printf("%d",numeroFlotante.flota.f13);
    printf("%d",numeroFlotante.flota.f14);
    printf("%d",numeroFlotante.flota.f15);
    printf("%d",numeroFlotante.flota.f16);
    printf("%d",numeroFlotante.flota.f17);
    printf("%d",numeroFlotante.flota.f18);
    printf("%d",numeroFlotante.flota.f19);
    printf("%d",numeroFlotante.flota.f20);
    printf("%d",numeroFlotante.flota.f21);
    printf("%d",numeroFlotante.flota.f22);
    printf("\n\n");
    
    
    return (0);
}
