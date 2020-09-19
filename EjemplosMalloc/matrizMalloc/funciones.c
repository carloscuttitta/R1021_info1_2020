#include"my.h"


void ingresoDatos( int **m , int file , int row)
{
    int i,j;

    printf("direccion de row traida por valor en funcion ingresoDatos %p\n",&row);
    printf("direccion de file traida por valor en funcion ingresoDatos %p\n",&file);
    printf("direccion de m traida por referencia en funcion ingresoDatos %p\n",&m);

    printf("direccion de i en funcion ingresoDatos %p\n",&i);
    printf("direccion de j en funcion ingresoDatos %p\n",&j);
    
    scanf("%d",&i);
    
    for ( i=0 ; i < file ; i++ )
    {
        for ( j=0 ; j < row ; j++ )
        {
            printf(" fila %d  columnas %d \t", i , j );
            scanf( "%d", &m[i][j] );
        }
        printf("\n");
    }
    printf("\n");
}

void imprimoMatriz( int **m , int file , int row)
{
    int i,j;
    
    printf("direccion de row traida por valor en funcion imprimoMatriz %p\n",&row);
    printf("direccion de file traida por valor en funcion imprimoMatriz %p\n",&file);
    printf("direccion de m traida por referencia en funcion imprimoMatriz %p\n",&m);

    printf("direccion de i en funcion imprimoMatriz %p\n",&i);
    printf("direccion de j en funcion imprimoMatriz %p\n",&j);



    for (i=0 ; i<file ; i++)
    {
        for (j=0 ; j < row ; j++)
        {
            printf("%d \t",m[i][j]);
        }
        printf("\n");
    }
}
   
   
void liberoMemoria(int ** m , int file )
{
    int i;
    
    for (i=0 ; i<file ; i++)
    {
        free(m[i]);
    }
    free(m);   
}    
    
int nada (void)
{
    
    return 0;
}
