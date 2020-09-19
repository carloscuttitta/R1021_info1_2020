

#include<stdio.h>


int main (void)
{
    long int numero;
    int i,j;
    unsigned char *p;
    
  
    numero = -65525;
    p =  (unsigned char *) &numero;
    i = sizeof(long int);
    for ( j=0 ; j<i ; j++)
    {
        printf("%d    %#x \n",j,*(p+j));      
    }   
}
        
        
