#include"my.h"

int imprimir_nombres(char **adr)
{
    int i;
    
    for(i=0 ; *(adr+i) != NULL ;i++){
    printf("\rnombre%d :%s ",i, *(adr+i) );
    }
    printf("\n");
    
    return (i-1);  // para sacarle el espacio que ocupa el NULL porque no es un nombre
}
    
    
int ordenar(int cant , char **direcciones)
{
    char *aux;
    int i=0,j=0,marca;
    do
    {
        marca=0;
        for(i=0 ; i < cant -j ;i++){
            if (strcmp( *(direcciones+i) , *(direcciones+i+1))>0)  // busco el menor  carlos  carlitos
            {
                aux = *(direcciones+i+1); 
                *(direcciones+i+1) = *(direcciones+i);
                *(direcciones+i)= aux;
                marca = 1;
            }
        }
        j++;
    }while(marca !=0);
    
   return 0; 
}

int myToupper(char * nombre)
{
    int    j;
      
    for ( j=0 ; *(nombre + j ) != '\0' ; j++ )
        {
            *(nombre + j ) = toupper ( *(nombre + j ) );
        }
    
 return 0;   
}
