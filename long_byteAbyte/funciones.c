#include"my.h"

void Valor_byte(int i , long int *a){//si te mandan una dirección de memoria tener en cuenta que el tipo de memoria que puede contener a dicha dirección debe ser de tipo puntero y por eso ponemos "long int *"
    int k; 
    unsigned char *p;
    p=(unsigned char *)a;// no pongo el & delate de "a" porque ya "a" es una direccion que me la mandaron

    for ( k=0 ; k<i ; k++)
    {
       printf("%p: \t 0x%.2x\n", p+k, p[k]);//0x%.2x para imprimir el valor en hexadecimal con formato de memoria(0x..)
    }
    printf("-------------------------\n");
    
    for ( k=0 ; k<i ; k++)
    {
       printf("%p: \t 0x%.2x\n", p+k , *(p+k));//0x%.2x para imprimir el valor en hexadecimal con formato de memoria(0x..)
    }
    
}



