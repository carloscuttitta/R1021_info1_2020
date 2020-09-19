/*
   Programa que tiene como objetivos:
   Leer un archivo.
   Crear un registro usando vector de memoria dinámica.
   Ordenar el registro.
   Generar nombre para un nuevo archivo de salida.
   Crear un nuevo archivo de salida y guardar el contenido del registro ordenado en el mismo.
   archivo 
*/
#include"my.h"

int main( int argc, char **argv )
{
    FILE * fd;
    FILE *fd_txt;
    int i,cont_reg=0;
    sensor_t **reg=NULL;
    char *arch_salida=NULL;
    char *arch_salida_txt=NULL;
    
    if(argc<2)
    {
        printf("ERROR - cantidad de argumentos incorrectos\n");
        return -1;
    }
    
    fd = fopen( *(argv+1), "r");
    
    if(fd==0)
    {
        printf("Error - no se abrio archivo\n");
    }
    
    SEPARADOR;
    printf("\nArchivo Ingresado:\t%s\n", *(argv+1) );
    
//CANTIDAD DE REGISTROS
    cont_reg = cuenta_reg( fd );    //retorna la cantidad de lineas leídas en el archivo (NO incluye el EOF)
    printf("Cantidad de registros: %d\n", cont_reg );
    SEPARADOR;
    
//MEMORIA PARA EL VECTOR REGISTRO
// crea para vector de direcciones    
    reg = (sensor_t **) malloc( sizeof(sensor_t * ) * cont_reg );   
    if(reg == NULL)
    {
        printf("ERROR CON MEMORIA EN reg");
        return -1;
    }
    
//SE REINICIA EL INDICE DEL ARCHIVO
    rewind( fd );
    
//CARGA DEL VECTOR REGISTRO
//extrae los strings de un archivo y carga el vector registro    
    carga_reg( fd , reg , cont_reg );   
    puts("\nREGISTRO:");
//imprime registro en pantalla    
    ver_registro( reg , cont_reg );      
    SEPARADOR;
    
//ORDENAMIENTO DEL VECTOR REGISTRO
//ordena el registro de menor a mayor
// TAREA : AGREGAR PUNTERO A FUNCION PARA ELEGIR COMO ORDENA !!!!!    
    ordena_reg ( reg, cont_reg );   
    printf("\nRegistro ordenado:\n");
    ver_registro( reg , cont_reg );
    SEPARADOR;
    
    fclose( fd );
    
//GENERA NOMBRE DE ARCHIVO DE SALIDA
    crea_nombre( &arch_salida , *(argv+1) , "-salida.dat" );
//    printf("archivo de salida: \t%s\n", arch_salida );

    
    //GENERA NOMBRE DE ARCHIVO DE SALIDA para un txt
    crea_nombre( &arch_salida_txt , *(argv+1) , "-salida.txt" );
//    printf("archivo de salida: \t%s\n", arch_salida_txt );

//GUARDA EN ARCHIVO DE SALIDA
    fd = fopen( arch_salida , "w" );
    if( fd==0 )
    {
        printf("ERROR - no se creo el archivo de salida %s\n", arch_salida );
    }
//carga el contenido del vector 'reg´ en el archivo de salida    
    escribe_archivo( fd , reg , cont_reg );   
    printf("ARCHIVO DE SALIDA %s GUARDADO\n",arch_salida);

//GUARDA EN ARCHIVO DE SALIDA en txt
    fd_txt = fopen( arch_salida_txt , "w" );
    if( fd_txt==0 )
    {
        printf("ERROR - no se creo el archivo de salida %s\n", arch_salida_txt );
    }
//carga el contenido del vector 'reg´ en el archivo de salida    
    escribe_archivo_txt( fd_txt , reg , cont_reg );   
    printf("ARCHIVO DE SALIDA %s GUARDADO\n",arch_salida_txt);


//SE MUESTRA EN PANTALLA EL ARCHIVO DE SALIDA    
    fclose( fd );   // lo cierro porque estaba solo como escritura
    fd = fopen( arch_salida, "r"); // abro el archivo que esta ordenado

    
// imprime en pantalla el contenido del archivo apuntado por fd.    
    cat( fd );    
    SEPARADOR;
    
//SE LIBERA MEMORIA ANTES DE SALIR DEL PROGRAMA    

    for(i=0;i<cont_reg;i++)
    {
        free( *(reg+i) );
    }
    
    free( reg );            
    free( arch_salida );       // es del malloc *buffer en crear nombre
    free( arch_salida_txt );   // es del malloc *buffer en crear nombre
    
    fclose( fd );
    fclose( fd_txt );
    return 0;
}

