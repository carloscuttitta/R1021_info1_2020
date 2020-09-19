#include"my.h"

int imprimir_nombres(datos_t **adr)
{
    int i=0;

    for(i=0 ; adr[i] != NULL ;i++){
        printf("%d    legajo-%ld   apellido-%s \n",i,adr[i]->legajo, adr[i]->apellido );
    }
    printf("\n");
    
    return (i);  // para sacarle el espacio que ocupa el NULL porque no es un nombre
}
    
