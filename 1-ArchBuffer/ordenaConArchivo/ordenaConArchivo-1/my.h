#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int id;
    time_t timestamp;
    char output[20];
    float valor;
    char unidad[10];
} sensor_t;


#define SEPARADOR   puts("+--------------------------------------+");

//FUNCIONES
int cuenta_reg( FILE * );
void carga_reg( FILE * , sensor_t **, int  );   
void ver_registro( sensor_t **, int );
void ordena_reg( sensor_t **, int  );  
void crea_nombre( char **, char *, const char *  );
void escribe_archivo( FILE *, sensor_t **, int );
void escribe_archivo_txt( FILE *, sensor_t **, int );
void cat(FILE *);
