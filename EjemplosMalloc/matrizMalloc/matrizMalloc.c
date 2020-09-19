#include"my.h"

int main (void)
{
    int **matriz=NULL;
    int filas,columnas,i;
    
/********  DEFINO TAMAÑO DE LA MATRIZ *************/
    printf("ingrese cantidad de filas y columnas \n");
    scanf("%d %d",&filas,&columnas);

    /********  RESERVO ESPACIO PARA EL TAMAÑO DEFINIDO *************/
    matriz = (int **) malloc ( filas * sizeof(int *) );
    if(matriz == NULL){
        printf("ERROR CON MEMORIA EN matriz");
    }

    for ( i=0 ; i < filas ; i++ )
    {
        matriz[i] = ( int * ) malloc ( columnas * sizeof(int) );
        if(matriz[i] == NULL){
            printf("ERROR CON MEMORIA EN matriz[%d]",i);
        }

    }

    /********  INGRESO LOS DATOS EN LA MATRIZ *************/
    ingresoDatos( matriz , filas , columnas );

    /********  IMPRIMO LA MATRIZ GENERADA *************/
    imprimoMatriz( matriz , filas , columnas );

    /********  LIBERO MEMORIA  *************/
    liberoMemoria( matriz , filas );

    return (0);
}
        
    
    

