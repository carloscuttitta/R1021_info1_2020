/*
   Programa que tiene como objetivos:
   Leer un archivo bmp.
   Crear un registro usando vector de memoria dinámica.
   Generar nombre para un nuevo archivo de salida.
   Crear un nuevo archivo de salida cambiando la imagea a una DILATADA.
*/
#include"my.h"

int main( int argc, char **argv )
{
    FILE * fdin;
    FILE * fdout;
    bmpFileHeader header;           /* cabecera */
    bmpInfoHeader bInfoHeader;
    unsigned int *imgdata,*aux_img;          /* datos de imagen */
    unsigned short type;            /* 2 bytes identificativos */
    char *arch_salida=NULL;
    
    if(argc<2){
        printf("ERROR - cantidad de argumentos incorrectos\n");
        return -1;
    }
    printf("\nArchivo Ingresado:\t%s\n", *(argv+1) );
    
//GENERA NOMBRE DE ARCHIVO DE SALIDA
    crea_nombre( &arch_salida , *(argv+1) , "-dilata.bmp" );

    fdin = fopen( *(argv+1), "r");
    if(fdin==0){
        printf("Error - no se abrio archivo\n");
        return 1;
    }

/* Leemos los dos primeros bytes */
    fread(&type, sizeof(unsigned short), 1, fdin);

    if (type !=0x4D42){          /* Comprobamos el formato */
      fclose(fdin);
      return 1;
    }

    fdout = fopen( arch_salida , "w" );
    if( fdout==0 ){
        printf("ERROR - no se creo el archivo de salida \n");
    }

    fwrite(&type, sizeof(unsigned short), 1, fdout);
    
/* Leemos la cabecera de fichero completa */
    fread(&header, sizeof(bmpFileHeader), 1, fdin);

    fwrite(&header, sizeof(bmpFileHeader), 1, fdout);

/* Leemos la cabecera de información completa */
    fread(&bInfoHeader, sizeof(bmpInfoHeader), 1, fdin);
  
    fwrite(&bInfoHeader, sizeof(bmpInfoHeader), 1, fdout);

/* Reservamos memoria para la imagen, ¿cuánta?
     Tanto como indique imgsize */

    printf("width:%d\n",bInfoHeader.width);
    printf("height:%d\n",bInfoHeader.height);
    printf("imgsize:%d\n",bInfoHeader.imgsize);
    printf("total:%d\n",bInfoHeader.width*bInfoHeader.height*4);
    
    imgdata=(unsigned int*)malloc(bInfoHeader.imgsize);
    aux_img=(unsigned int*)malloc(bInfoHeader.imgsize);

/* Nos situamos en el sitio donde empiezan los datos de imagen,
   nos lo indica el offset de la cabecera de fichero*/

    printf("header.offset:%d\n",header.offset);
    fseek(fdin, header.offset, SEEK_SET);

/* Leemos los datos de imagen, tantos bytes como imgsize */
    fread(imgdata, bInfoHeader.imgsize,1, fdin);
        
    printf("voy a erosionar\n");
    dilata ( imgdata , aux_img , bInfoHeader);

    fwrite(imgdata, bInfoHeader.imgsize,1, fdout);
    printf("ARCHIVO DE SALIDA %s GUARDADO\n",arch_salida);

//SE LIBERA MEMORIA ANTES DE SALIR DEL PROGRAMA    
    free( arch_salida );       // es del malloc *buffer en crear nombre
    free(imgdata);
    free(aux_img);

    fclose( fdin );
    fclose( fdout );
    return 0;
}
