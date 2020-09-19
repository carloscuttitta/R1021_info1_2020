 /* Compilar:
      gcc -c rot13.c -o rot13.o -Wall
  Linkear:
      gcc rot13.o -o rot13 -Wall
*/ 
#include <stdio.h>

int rot_13(char*dataPtr);        

int main(void)
{
char dataPtr[] = { "HOLA MUNDO" };        
int devuelve;

  printf("%s\r\n",dataPtr);
  devuelve=rot_13(dataPtr);         
  printf("%s   %d\r\n",dataPtr,devuelve);
  return (devuelve);
}
int rot_13(char *dataPtr)
{
char caracter;
int i = 0;        
int contador=0;
  while (dataPtr[i] != '\0') {        
    caracter = dataPtr[i];              
    if (caracter >= 'A' && caracter < 'N') {                
      dataPtr[i] = caracter + 13;               
      contador++;
    } else if (caracter >= 'N' && caracter <= 'Z') {        
      dataPtr[i] = caracter - 13;               
      contador++;
    } else if (caracter < 'A' || caracter > 'Z') {         
      if (caracter !=' '){
	contador=-1;
	break;
      }
    }
    i++;        
  }
  return(contador);
}
