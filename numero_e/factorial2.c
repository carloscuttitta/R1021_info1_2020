#include <stdio.h>
#include <math.h>

#define PRECISION   pow(10,-9)
int  main(void)
{
int factorial = 1,contador =1,i;    
double   numeroEuler=0,numeroEulerOld=-1;

for(i=0;(numeroEuler-numeroEulerOld)>= PRECISION;i++)
    {
        numeroEulerOld=numeroEuler;
        while(contador <= i)
        { 
            printf("i=%d \t contador=%d\n",i,contador);
            factorial = factorial * contador;
            contador++;
        }
        numeroEuler = numeroEuler + (1/(double)factorial); 
        printf("El numero e es %0.10f \n",numeroEuler);
        
        factorial = 1;
        contador =1;
    }
    printf("El numero Old de e es %0.10f \t  diferencia es %0.10f \n",numeroEulerOld,(numeroEuler-numeroEulerOld));
    printf("El numero e (de la lib math.h) es %0.10f \n",M_E);
    return 0;
}

