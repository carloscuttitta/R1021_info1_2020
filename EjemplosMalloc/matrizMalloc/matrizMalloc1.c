#include"my.h"

int main (void)
{
    int **matriz=NULL;
    int filas,columnas,i=0,j=0;
    int (* quehago) (void) = main;

    
    printf("direccion matriz al asignarla %p\n",&matriz);
    printf("direccion filas al asignarla %p\n",&filas);
    printf("direccion columnas al asignarla %p\n",&columnas);
    printf("direccion de i=0 al asignarla %p\n",&i);
    printf("direccion de j=0 al asignarla %p\n",&j);
    printf("direccion de funcion main %p\n",quehago);
    
    
/********  DEFINO TAMAÑO DE LA MATRIZ *************/
    printf("ingrese cantidad de filas y columnas \n");
    scanf("%d %d",&filas,&columnas);

    /********  RESERVO ESPACIO PARA EL TAMAÑO DEFINIDO *************/
    matriz = (int **) malloc ( filas * sizeof(int *) );
    if(matriz == NULL){
        printf("ERROR CON MEMORIA EN matriz");
    }
printf("direccin de matriz entregada por malloc %p\n",matriz);
    for ( i=0 ; i < filas ; i++ )
    {
        matriz[i] = ( int * ) malloc ( columnas * sizeof(int) );
        if(matriz[i] == NULL){
            printf("ERROR CON MEMORIA EN matriz[%d]",i);
        }

    }
printf("direccin de matriz[0] entregada por malloc %p\n",matriz[0]);
printf("direccin de matriz[1] entregada por malloc %p\n",matriz[1]);

    /********  INGRESO LOS DATOS EN LA MATRIZ *************/
    ingresoDatos( matriz , filas , columnas );

    /********  IMPRIMO LA MATRIZ GENERADA *************/
    imprimoMatriz( matriz , filas , columnas );

    /********  LIBERO MEMORIA  *************/
    liberoMemoria( matriz , filas );

    return (0);
}
        
    
    

