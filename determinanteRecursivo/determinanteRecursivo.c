#include"my.h"


int main (void)
{
    int **matriz;
    int filas,columnas,i,j;
    int determinante;
    
/********  DEFINO TAMAÑO DE LA MATRIZ *************/
    printf("ingrese cantidad de filas y columnas \n");
    scanf("%d %d",&filas,&columnas);
    
/********  RESERVO ESPACIO PARA EL TAMAÑO DEFINIDO *************/
    matriz = (int **)malloc (filas*sizeof(int *));
    for (i=0 ; i<filas ; i++)
    {
        matriz[i] = (int *) malloc (columnas*sizeof(int));
    }

/********  INGRESO LOS DATOS EN LA MATRIZ *************/
    for (i=0 ; i<filas ; i++)
    {
        for (j=0 ; j<columnas ; j++)
        {
//            printf("ingrese dato para fila %d  columnas %d \n",i,j);
            scanf("%d",&matriz[i][j]);
        }
    }
    printf("\n");

/********  IMPRIMO LA MATRIZ GENERADA *************/
    for (i=0 ; i<filas ; i++)
    {
        for (j=0 ; j<columnas ; j++)
        {
            printf("%d \t",matriz[i][j]);
        }
        printf("\n");
    }
    if ( filas == columnas )
    {
        determinante = det( matriz , i );
        printf("El determinante de la matriz %d x %d es  %d\n", filas,columnas,determinante);
    }else{
        printf("No es una matriz cuadrada \n");
    }
    
/********  LIBERO MEMORIA  *************/
    for (i=0 ; i<filas ; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
    return (0);
}
    
