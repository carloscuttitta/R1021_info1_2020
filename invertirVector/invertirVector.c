// compilar gcc -c invertirVector.c -o invertirVector.o -Wall
// linkear  gcc  invertirVector.o -o main

#include<stdio.h>
#define TAM 30

int invertir (char * v , char * invertirV );

int main (void)
{
    char vector[TAM];
    char vectorInvertido[TAM];
    
    printf("\n");
    printf("ingrese string para invertir sus caracteres\n");
    scanf("%s",vector);
    printf(" ingreso %s \n",vector);
    invertir ( vector , vectorInvertido );
    printf(" el vector invertido es ingreso %s \n", vectorInvertido);

    return 0;
}


int invertir (char * v , char * invertirV )
{
int i=0 , j;
    
    while ( *(v+i) != '\0')
    {
        i++;
    }

    invertirV[i] = '\0';

    for (j=0 ; *(v+j) != '\0' ; j++ )
    {
        i--;
        *(invertirV + j)  = *( v + i);
    }
    
    return 0;
}    
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    

