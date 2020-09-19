
#include"my.h"

int main (void)
{
    int i=0,j,cantidad;
    char    nombres[TAM];
    datos_t ** adr;
    long    aux_legajo;
    
    adr= (datos_t **) malloc(sizeof(datos_t *));  //inicializo "adr" en el espacio reservado
    if(adr == NULL){
        printf("ERROR CON MEMORIA EN adr");
    }
    
    do{
        printf("ingrese legajo\n");
        scanf("%ld",&aux_legajo);
        getc(stdin);
        printf("ingrese apellido\n");
        fgets(nombres , TAM , stdin );
        for (j=0;nombres[j]!='\0';j++){ // lo uso para buscar el valor de i donde está el null
        }  
        nombres[j-1]='\0';   // elimino el salto de linea que escribió en nombre corriendo el null
        
        adr[i] = (datos_t *) malloc ( sizeof(datos_t) );
        if(adr[i] == NULL){
            printf("ERROR CON MEMORIA EN adr[%d]",i);
        }

        adr[i]->legajo=aux_legajo;
        strcpy(adr[i]->apellido , nombres);
        
        
        if ( aux_legajo  != 0 ){
            adr = (datos_t **) realloc( adr ,(i+2)* sizeof(datos_t *)); 
            if(adr == NULL){
                printf("ERROR CON MEMORIA EN adr");
            }
            i++;
        }else{
            free(adr[i]);
            adr[i] = NULL;  
        }

    }while( aux_legajo != 0 );
    
        cantidad = imprimir_nombres(adr);
        printf("%d\n",cantidad);

        for(i=0 ; *(adr+i) != NULL ;i++){
            free(*(adr+i) );
        }
    
        free (adr);
        
        return 0;
}

