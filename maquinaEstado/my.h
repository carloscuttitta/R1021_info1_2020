#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef	unsigned char        uint8_t;

typedef struct{
    int id;
    time_t timestamp;
    char output[20];
    float valor;
    char unidad[10];
} sensor_t;

struct alfa{
    uint8_t b0_b3:4;
    uint8_t b4_7:4;   // reservados
};

union seleccion {
    uint8_t     estado;
    struct alfa bites;
};

#define SEPARADOR   puts("+--------------------------------------+");

//FUNCIONES
int cuenta_reg( FILE * );
void carga_reg( FILE * , sensor_t **, int  );   
void ordTime( sensor_t **, int  );  
void ordUnidad( sensor_t **, int  );  
void crea_nombre( char **, char *, const char *  );
void escribe_archivo( FILE *, sensor_t **, int );
void escribe_archivo_txt( FILE *, sensor_t **, int );

//FUNCIONES PARA MAQUINA DE ESTADOS
void promAmpere( sensor_t **, int  );  
void promTension( sensor_t **, int  );  
void promVelocidad( sensor_t **, int  );  
void promFrecuencia( sensor_t **, int  );  
void promAceleracion( sensor_t **, int  );  
void promFuerza( sensor_t **, int  );  
