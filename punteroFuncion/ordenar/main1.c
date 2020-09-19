#include <stdio.h>
#include "funciones.h"

#define     MAXIMO      10

int main ( void )
{
    int Datos[ MAXIMO ] = {8,5,6,1,10,20,4,2,9,0};
    //int Datos[ MAXIMO ] = {0,1,2,4,5,6,8,9,10,20};
    int i, elijo;
    
    int (* ordeno) (int, int);

    for ( i = 0 ; i < MAXIMO ; i++ )
    {   
        printf ("%d\n",Datos[i]);
    }   
    printf ("\n");

    printf ("queres ordenar de menor a mayor (1) o de mayor a menor (cualquier otro)?: ");
    scanf("%d", &elijo);
    
    if(elijo==1) ordeno = mayor;
    else ordeno = menor;
    
    bellota (Datos, MAXIMO, ordeno);
    
    for ( i = 0 ; i < MAXIMO ; i++ )
    {   
        printf ("%d\n",Datos[i]);
    }
    return 0;
}

        
           
