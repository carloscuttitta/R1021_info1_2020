#include <stdio.h>

int main (void)
{
char datoChar;
//-- Ingreso de datos --
  printf("Ingrese valor entero: ");
  scanf("%c", &datoChar);
//-- Impresión de datos --
  printf("size del char       :\t%d\r\n",(int)sizeof(datoChar));
  printf("el dato en decimal  :\t%d\r\n",datoChar);  
  printf("dirección en memoria:\t%p\r\n", &datoChar);
  printf("el dato en hexa     :\t%#x\r\n",datoChar);  
  printf("el dato en hexa     :\t%x\r\n",datoChar);  
  printf("el dato en octal    :\t%o\r\n",datoChar);  
  printf("el caracter es      :\t%c\r\n",datoChar);  
return (0);
}