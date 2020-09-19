#include"my.h"

int imprimir_desordenados(char **adr)
{
    int i;
    
    for(i=0 ; *(adr+i) != NULL ;i++){
    printf("\rnombre%d :%s     %p     %p\n ",i, *(adr+i) ,*(adr+i) , (adr+i) );
    }
    return 0;
}
    
int buscarAlfabeticamente_primero(char **direcciones)
{
    char *aux;
    int i=0,posicion=0;
    
    aux= *(direcciones);

    for(i=0 ; *(direcciones+i) != NULL ;i++){
        if (strcmp( aux,*(direcciones+i))>0)  // busco el menor
        {
            aux = *(direcciones+i); 
            posicion = i;
        }
    }
    return posicion;
}
    
