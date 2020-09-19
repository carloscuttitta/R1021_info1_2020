/* asignar memoria dinamicamente al vector que contiene las adr de los nombres ingresados y utilizar la memoria justa para cada nombre ( la idea es que si generé un vector de 256 elementos pero ingreso un nombre que ocupa 5, usemos los recursos para que sólo se usen los espacios para esos 5 y que no genére 256 espacios siempre por mas que no los usemos). Temina el programa cuando un nombre comienza con el simbolo @ */

/* probar usando ./main < entrada.txt > salida.txt
 es una manera de redirigir la entrada y que no sea por stdin sino por los datos que contiene el archivo //  entrada y luego usar el comando > que indica que la salida cambia de stdout (consola) al archivo salida.txt . luego podemos analizar al archivo para no andar recorriendo la consola

 Imprimir el primer nombre alfabeticamente
 */

#include"my.h"

int main (void)
{
    int i=0,j;
    char    c,nombres[TAM];
    char * p;
    char ** adr;
    
    adr= (char **) malloc(sizeof(char *));  //inicializo "adr" en el espacio reservado
    if(adr == NULL){
        printf("ERROR CON MEMORIA EN adr");
    }
    
    do{
// IMPORTANTE !!!!
// Si usan scanf("%s",nombres); deben tener en cuenta que no va a contar el NULL mientras que 
// fgets(nombres , TAM , stdin ); SI QUE CUENTA AL NULL      

        fgets(nombres , TAM , stdin ); 
        j = strlen(nombres);
        p = (char *) malloc (j*sizeof(char));
        if(p == NULL){
            printf("ERROR CON MEMORIA EN p");
        }
        strcpy ( p , nombres);
        *(adr + i) = p;     

        c = *(*(adr+i));
        if ( c != '@' ){
            adr = (char **) realloc( adr ,(i+2)* sizeof(char *)); 
            if(adr == NULL){
                printf("ERROR CON MEMORIA EN adr");
            }
            i++;
        }else{
            free(p);
            *(adr + i) = NULL;  
        }

    }while( c != '@' );

        imprimir_desordenados(adr);

        i = buscarAlfabeticamente_primero(adr);

        printf("\nEL PRIMERO ALFABETICAMENTE DE LA LISTA ES :  %s \n",*(adr+i));

        for(i=0 ; *(adr+i) != NULL ;i++){
            free(*(adr+i) );
        }
        free (adr);
        
        return 0;
}

