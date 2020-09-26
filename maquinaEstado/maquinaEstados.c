/*
    Programa que tiene como objetivos:
    Leer el archivo creado por el programa crear_datos.
    Crear un registro usando vector de memoria dinámica.
    Utilizar un puntero a función para que actúe como maquina de estados ( por ahora usar 
    random luego usaremos IPC para usar esos datos).
    usar una mascara para que sólo maneje 8 estados posibles.
    ordTime         para    0x00 
    ordUnidad       para    0x01
    promAmpere      para    0x02
    promTension     para    0x03
    promVelocidad   para    0x04
    promFrecuencia  para    0x05
    promAceleracion para    0x06
    promFuerza      para    0x07
    Generar nombres para los nuevos archivos de salida ( para datos: [nombe de archivco]-salida.dat
    y para texto: [nombe de archivco]-salida.txt).
    Crear los nuevos archivos de salida  y guardar el contenido del registro ordenado.

    Juan Carlos Cuttitta        
    carloscuttitta@gmail.com
*/
#include"my.h"

int main( int argc, char **argv )
{
    FILE * fd;
    FILE *fd_txt;
    int i,cont_reg=0;
    char *arch_salida=NULL;
    char *arch_salida_txt=NULL;
    sensor_t **reg=NULL;
    union seleccion aleatorio;
// Puntero a funcion    
    void (* comoOrdeno[]) (sensor_t **, int ) ={ordTime,            //  0x00 
                                                ordUnidad,          //  0x01
                                                promAmpere,         //  0x02
                                                promTension,        //  0x03
                                                promVelocidad,      //  0x04
                                                promFrecuencia,     //  0x05
                                                promAceleracion,    //  0x06
                                                promFuerza          //  0x07
                                                };

    
    if(argc !=2){
        printf("ERROR - cantidad de argumentos incorrectos\n");
        return -1;
    }
    
    fd = fopen( *(argv+1), "r");
    if(fd==0){
        printf("Error - no se abrio archivo\n");
    }
    
    printf("Archivo Ingresado:\t%s\n", *(argv+1) );
    
//CANTIDAD DE REGISTROS
//retorna la cantidad de lineas leídas en el archivo (NO incluye el EOF)    
    cont_reg = cuenta_reg( fd );    
    printf("Cantidad de registros: %d\n", cont_reg );
    SEPARADOR;
    
//MEMORIA PARA EL VECTOR REGISTRO
// crea para vector de direcciones que va a apuntar a cada estructura leida   
    reg = (sensor_t **) malloc( sizeof(sensor_t * ) * cont_reg );   
    if(reg == NULL){
        printf("ERROR CON MEMORIA EN reg");
        return -1;
    }
    
//SE REINICIA EL INDICE DEL ARCHIVO
    rewind( fd );
    
//CARGA DEL VECTOR REGISTRO
//extrae los datos del archivo y carga el vector registro    
    carga_reg( fd , reg , cont_reg );   
    
// MAQUINA DE ESTADOS con puntero a funcion
// inicializo la semilla para que rand() sea siempre distinto cada vez que se ejecute    
    srand (time(NULL));
// Proximamente este número me lo tiene que entregar otro proceso que esté ejecutandose en otra terminal 
// utilizando alguna IPC y en caso de usar socket , desde otra computadora !!     
    aleatorio.estado = rand()%1024;
    aleatorio.estado = aleatorio.estado & 0x07;
    
    printf("random es %d \n",aleatorio.estado);
    
    comoOrdeno[aleatorio.bites.b0_b3] (reg, cont_reg); 
    
    fclose( fd );
    
//GENERA NOMBRE DE ARCHIVO DE SALIDA
    crea_nombre( &arch_salida , *(argv+1) , "-salida.dat" );
    printf("archivo de salida: \t%s\n", arch_salida );
    
//GENERA NOMBRE DE ARCHIVO DE SALIDA para un txt
    crea_nombre( &arch_salida_txt , *(argv+1) , "-salida.txt" );
    printf("archivo de salida: \t%s\n", arch_salida_txt );

//GUARDA EN ARCHIVO DE SALIDA
    fd = fopen( arch_salida , "w" );
    if( fd==0 ){
        printf("ERROR - no se creo el archivo de salida %s\n", arch_salida );
    }
//carga el contenido del vector 'reg´ en el archivo de salida    
    escribe_archivo( fd , reg , cont_reg );   

//GUARDA EN ARCHIVO DE SALIDA en txt
    fd_txt = fopen( arch_salida_txt , "w" );
    if( fd_txt==0 ){
        printf("ERROR - no se creo el archivo de salida %s\n", arch_salida_txt );
    }
//carga el contenido del vector 'reg´ en el archivo de salida    
    escribe_archivo_txt( fd_txt , reg , cont_reg );   
    
//SE LIBERA MEMORIA ANTES DE SALIR DEL PROGRAMA    
    for(i=0;i<cont_reg;i++){
        free( *(reg+i) );
    }
    
    free( reg );            
    free( arch_salida );       // es del malloc *buffer en crear nombre
    free( arch_salida_txt );   // es del malloc *buffer en crear nombre
    
    fclose( fd );
    fclose( fd_txt );
    return 0;
}

