#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main()
{
    char *token;
    char cadena[100];
    FILE *fd_txt;

/* Con un puntero a DIR abriremos el directorio */
    DIR *dir;
/* en *ent habrá información sobre el archivo que se está "sacando" a cada momento */
    struct dirent *ent;

/*  struct dirent {
        ino_t          d_ino;           Inode number 
        off_t          d_off;           Not an offset; see below 
        unsigned short d_reclen;        Length of this record 
        unsigned char  d_type;          Type of file; not supported by all filesystem types 
        char           d_name[256];     Null-terminated filename 
    };
*/

    
/* Empezaremos a leer en el directorio actual */
    dir = opendir ("./sent");
/* Miramos que no haya error */
    if (dir == NULL){
        printf("No puedo abrir el directorio");
        exit(1);
    }

    fd_txt = fopen( "listado.txt" , "w" );
    if( fd_txt==0 ){
        printf("ERROR - no se creo el archivo de salida \n");
        exit(1);
    }
    
    
    
/* Leyendo uno a uno todos los archivos que hay */
    while ((ent = readdir (dir)) != NULL){
/* Nos devolverá el directorio actual (.) y el anterior (..), como hace ls */
        if ( ( strcmp(ent->d_name, ".") !=0 ) && (strcmp(ent->d_name, "..")!=0) ){
            strcpy(cadena,ent->d_name);
            token = strtok(ent->d_name, ".");
            if( (token != NULL) && ( (strcmp(cadena,token) != 0) ) ){
                fprintf(fd_txt,"%s\n",cadena);   
                printf ("%s \n", cadena);
            }
        }
    }
    fclose(fd_txt);
    closedir (dir);
    return EXIT_SUCCESS;
}


