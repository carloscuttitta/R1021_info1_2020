#include"my.h"

long int potencia ( int *a, int *b)
{
    long int c=1;
    unsigned char *p;
    
    p= (unsigned char *)a;   // no pongo el & porque a ya es una direccion
   
    
    while ((*b) != 0)
    {
        c=c*(*a);
        (*b)--;
    }
    
    printf("int %ld \n",sizeof(int));
    printf("int %ld \n",sizeof(short int));

    printf("valor1 %#.2x \n",*p);
    printf("valor2 %#.2x \n",*(p+1));
    printf("valor3 %#.2x \n",*(p+2));
    printf("valor4 %#.2x \n",*(p+3));
    
    
    return c;
}
    
        
