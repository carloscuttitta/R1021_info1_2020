#include "factorial.h"
 
int  main(void)
{
int n,resultadoFactorial;

    printf("Ingrese un numero para el factorial: ");

    scanf("%d",&n);

    resultadoFactorial = factorial ( n );
    
    printf("El factorial de %d es: %d\n", n , resultadoFactorial);
 
    return 0;
}
