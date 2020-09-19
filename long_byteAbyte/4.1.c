/*Escriba una función que imprima, byte a byte, los bytes que constituyen una
variable long cuya dirección recibe como argumento.*/
#include"my.h"

int main(void)
{
    long int dato;
    int     j;
    
    printf("num: ");
    scanf("%ld", &dato);
    j = sizeof(dato);   // sizeof(long int) 
    printf("j:%d ",j);
    
    Valor_byte(j,&dato);// envio entero por "valor" direccion por "referencia" Valor_byte(int,long int *)
    return 0;
}


