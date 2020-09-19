// compilar gcc -c ejemplo.c -o ejemplo.o -Wall
// linkear  gcc  ejemplo.o -o ejemplo

/* compilar gcc -c ejemplo.c -o ejemplo.o -Wall
 linkear  gcc  ejemplo.o -o ejemplo -Wall   */

#include"my.h"

int main (void)
{
    long int resultado;
    int     x,y;
    
    scanf("%d",&x);
    scanf("%d",&y);
    
    resultado = potencia ( &x, &y);
    
    printf("la pot es %ld \n",resultado);

    return 0;
}



        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    

