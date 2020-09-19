#include <stdio.h>
#include <string.h>

#define     Max     4

int main ( void )
{
    
typedef struct {          // la tengo que poner en el .h
        char Nombre[ 21 ];
        char Apellido[ 21 ];
        float Pnota[ 6 ];
        int legajo;
    }datos_t;
    
    int i , k , marca ;
    datos_t D[ Max ] , *Indice[ Max ] , *Aux;
    
    for ( i = 0 ; i < Max ; i ++ )
    {
        printf ( "Nombre:");
        scanf("%s",D[i].Nombre);
        printf ( "Apellido:");
        scanf("%s",D[i].Apellido);
        Indice[ i ] = & ( D[i] ) ; // guarda la direccion de cada estructura
    }
    
    do
    {
        marca = 0;
        for ( i = 0 , k = 0 ; i < Max - 1 - k ; i++ )
        {
            if ( strcmp ( Indice[ i ]->Apellido ,Indice[ i + 1]->Apellido) > 0 )
            {
                marca = 1;
                Aux = Indice[ i ];
                Indice[ i ] = Indice[ i + 1 ];
                Indice[ i + 1 ] = Aux ;
            }
        }
        k++;
    }
    while ( marca );
    
    printf ( "Vector D --------------------------\n"); // imprimo como lo ingrese
    for ( i = 0 ; i < Max ; i ++ )
    {
        printf ( "Nombre: %s \n", D[i].Nombre);
        printf ( "Apellido:%s \n",D[i].Apellido);
    }
    printf ( "Vector D por indireccion ----------\n");  // imprimo ordenado
    for ( i = 0 ; i < Max ; i ++ )
    {
        printf ( "Apellido:%s\tNombre: %s \n", Indice[i]->Apellido,Indice[i]->Nombre);
    }
    return 0;
}

    
