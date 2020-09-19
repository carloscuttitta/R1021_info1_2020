#include"my.h"

int main (int argc , char **argv)
{
    int i=0,j=0;
    char ** adr=NULL;
    
    for ( i=1 ; i < argc ; i++ ,j++)
    {    
         adr = (char **) realloc( adr ,i * sizeof(char *)); 
         if(adr == NULL){
            printf("ERROR CON MEMORIA EN adr");
        }
        *(adr + j) = *(argv + i);
    }
         adr = (char **) realloc( adr ,(i)* sizeof(char *)); 
         if(adr == NULL){
            printf("ERROR CON MEMORIA EN adr");
        }
        *(adr + j) = NULL;

        imprimir_desordenados(adr);

        i = buscarAlfabeticamente_primero(adr);

        printf("\nEL PRIMERO ALFABETICAMENTE DE LA LISTA ES :  %s \n",*(adr+i));

        free (adr);
        
        return 0;
}

