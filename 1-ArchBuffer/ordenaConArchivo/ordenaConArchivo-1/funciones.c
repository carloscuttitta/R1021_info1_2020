#include"my.h"
/* 
    fn: cuenta la cantidad de registros que tiene el archivo
    in: recibe un file descriptor.
    out:retorna un entero. Cantidad de registros
*/
int cuenta_reg(FILE *fd)
{
    int i=0;

    fseek(fd, 0, SEEK_END);
    i=ftell(fd);
    printf("cantidad de byte:%d\n",i);
    
    return (i/(sizeof(sensor_t)));
}

/*
    fn: lee el archivo y guarda su contenido en un vector de memoria dinamica.
    in: 1er arg: recibe un file descripto del archivo que se va a leer.
        2do arg: direccion del vector de registros.
        3er arg: cantidad de registros a leer.
*/
void carga_reg( FILE *fd , sensor_t **reg , int lineas_reg )
{
    sensor_t buffer;
    int i;
    for( i=0 ; i<lineas_reg ; i++ )
    {
//lee el registro y lo guarda en buffer         
        fread(&buffer, sizeof(sensor_t), 1, fd);
// pide memoria para el registro guardado en buffer        
        reg[i] = (sensor_t *) malloc( sizeof(sensor_t));
//copia el contenido del buffer en el vector de registros.
        reg[i]->id = buffer.id;   
        reg[i]->timestamp = buffer.timestamp;   
        reg[i]->valor = buffer.valor;   
        strcpy(reg[i]->unidad, buffer.unidad);   
        strcpy(reg[i]->output, buffer.output);   
    }
}

/*
    fn: imprime en pantalla todos los registros cargados.
    in: 1er arg: direccion del vector de registros.
        2do arg: cantidad de registros.
*/
void ver_registro(sensor_t **reg, int lineas_reg)
{
    int i;
    for ( i=0 ; i < lineas_reg ; i++ )
    {
    printf("i=%d\tid=%d\ttimestamp=%ld\tfecha=%s\tvalor=%0.2f\tunidad=%s\n",i,(*(reg+i))->id,(*(reg+i))->timestamp,(*(reg+i))->output,(*(reg+i))->valor,(*(reg+i))->unidad);   
    }
}

/*
    fn: ordena el vector de registro de menor a mayor.
    in: 1er arg: direccion del vector de registros.
        2do arg: cantidad de registros.
*/    
void ordena_reg ( sensor_t **reg, int lineas_reg )
{
    int i , j , cont=0;
    sensor_t *buffer;
//ORDENAMIENTO
    for ( i = 0 ; i < lineas_reg - 1 ; i++ )
    {
        for ( j = 0 ; j < lineas_reg - 1 - i; j++ )
        {
            cont++;
            if ( strcmp( (*(reg+j))->unidad , (*(reg+j+1))->unidad ) > 0 )    //strcmp(reg[ j ] , reg[ j + 1]) > 0
            {
                buffer =*(reg+j+1);          //buffer = reg[j+1];
                *(reg+j+1)=*(reg+j);        //reg[j+1] = reg[j];
                *(reg+j)= buffer;            //reg[j] = buffer;  
            }
        }
    }
}

/*
    fn: crea el nombre de un archivo.
    in: 1er arg: direccion de memoria del buffer para guardar el nuevo nombre del archivo.
        2do arg: direccion de memoria al vector que contiene el nombre del archivo original.
        3ro arg: direccion de memoria de un strings del tipo constante. Este contiene parte del nombre para el archivo de salida.
*/            
void crea_nombre(char **buffer, char *in_nombre, const char * s)
{
    int i=0;
    char *nombre=NULL;
//cuenta la cantidad de caracteres hasta que encuentra  '.'    
    for( i=0 ; *(in_nombre+i) != '.' ; i++ ){   
    }

//EXTRACION DEL NOMBRE DEL ARCHIVO ORIGINAL
    nombre = (char *) malloc( sizeof(char) + i );    //se toma memoria segun el contador 'i´.

    for( i=0 ; *(in_nombre+i) != '.' ; i++ ){
//se carga el string contenido en 'reg´ en 'nombre´ hasta encontrar el '.'        
        *(nombre+i) = *(in_nombre+i);    
    }
//se agrega '\0' al final del string    
    *(nombre+i) = '\0';     
    
//COMPOSICION DEL NOMBRE DEL ARCHIVO DE SALIDA
//descuento 1 al contador correspondiente '\0'
    i--;    
//pide memoria segun la suma 'i´+ cantidad de caracteres de s + 1.    
    *buffer = (char *) malloc(sizeof(char) * i + strlen(s) + 1);  
//se copia el string contenido en 'nombre´ al inicio del 'buffer´
    strcpy( *buffer , nombre );     
//se agrega el string contenido en 's´ al final del buffer.
    strcat( *buffer , s );     
//se libera memoria    
    free(nombre); 
}

/*
    fn: escribe en un archivo lo contenido en un vector de memoria dinamica.
    in: 1er arg: file descriptor del archivo a escribir.
        2do arg: direccion de memoria del vector de registros.
        3ro arg: valor entero. Cantidad de registros.
*/
void escribe_archivo( FILE *fd, sensor_t **reg , int lineas_reg )
{
    int i=0;
    while( i<lineas_reg )
    {
//	fwrite((char *)&reg[i], sizeof(sensor_t), lineas_reg, fd);
	fwrite(reg[i], sizeof(sensor_t), 1, fd);

        i++;
    }
}

/*
    fn: escribe en un archivo lo contenido en un vector de memoria dinamica.
    in: 1er arg: file descriptor del archivo a escribir.
        2do arg: direccion de memoria del vector de registros.
        3ro arg: valor entero. Cantidad de registros.
*/
void escribe_archivo_txt( FILE *fd_txt, sensor_t **reg , int lineas_reg )
{
    int i=0;
    while( i<lineas_reg )
    {
    fprintf(fd_txt,"%d\t%ld\t%s\t%0.2f\t%s\n",(*(reg+i))->id,(*(reg+i))->timestamp,(*(reg+i))->output,(*(reg+i))->valor,(*(reg+i))->unidad );   
        i++;
    }
}


void cat( FILE *fd)
{
    sensor_t buffer;
    
    do
    {
    fread(&buffer, sizeof(sensor_t), 1, fd);
//con este if() evito que se imprima 2 veces la ultima linea.
        if( !feof(fd))
        {
            printf("id=%d\ttimestamp=%ld\tfecha=%s\tvalor=%0.2f\tunidad=%s\n",buffer.id,buffer.timestamp,buffer.output,buffer.valor,buffer.unidad);
        }
    }while(!feof(fd));

}

