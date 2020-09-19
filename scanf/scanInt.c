#include <stdio.h>

int main (void)
{
int datoInt;
//-- Ingreso de datos --
  printf("Ingrese valor entero: ");
  scanf("%d", &datoInt);
//-- Impresión de datos --
  printf("size del int        :\t%d\n",(int)sizeof(datoInt));
  printf("el dato en decimal  :\t%d\n",datoInt);  
  printf("dirección en memoria:\t%p\n", &datoInt);
  printf("el dato en hexa     :\t%#x\n",datoInt);  
  printf("el dato en hexa     :\t%x\n",datoInt);  
  printf("el dato en octal    :\t%o\n",datoInt);  
return (0);
}
