#include "factorial.h"

int factorial(int numero)
{
    int factorial = 1,contador =1;
    
        while(contador <= numero)
    { 
        factorial = factorial * contador;
        contador++;
    }

    return factorial;
}

