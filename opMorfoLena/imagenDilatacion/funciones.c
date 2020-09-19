#include"my.h"

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
    0        1       2       3       4      ...... 629              primeros 630 pixeles   width
    630     631     632     633     634     ...... 1259
    1260    1261    1262    1263    1264    ...... 1889
    1890    1891    1892    1893    1894    ...... 2519
    ...
    ...
    396270  396271  396272  396273  396274  ......396899
 
buscamos el mayor de los que rodea a X y ponemos X=mayor     
   |----------------------|
   |X-631   X-630   X-629 |    3       4      ......    628     629              
   |X-1       X     X+1   |   633     634     ......    1258    1259
   |X+629   X+630   X+631 |   1263    1264    ......    1888    1889
   |----------------------| 
    1890    1891    1892      1893    1894    ......    2518    2519
    ...
    395640  395641  395642    395643  395644  ......    396268  396269
    396270  396271  396272    396273  396274  ......    396898  396899  
     
     X comienza en 631 y termina en 396268
 */
void dilata ( unsigned int *imgdata , unsigned int *aux_img , bmpInfoHeader bInfoHeader)
{
    unsigned int mayor,i;          

    for (i=bInfoHeader.width+1; i < bInfoHeader.width*(bInfoHeader.height-2);i++){   
        mayor = *(imgdata+i) ;    // este es el pixel X

        if( ( *(imgdata + ( i-1 ) ) )  > mayor ){                       //X-1
            mayor = *(imgdata+(i-1));
        }

        if( ( *(imgdata + ( i+1 ) ) )  > mayor ){                       //X+1
            mayor = *(imgdata+(i+1));
        }

        if( ( *(imgdata + ( i-( bInfoHeader.width+1 ) ) ) ) > mayor ){  //X-631
            mayor = *(imgdata+(i-(bInfoHeader.width+1)));
        }

        if( ( *(imgdata + ( i-( bInfoHeader.width ) ) ) ) > mayor ){    //X-630
            mayor = *(imgdata+(i-(bInfoHeader.width)));
        }
     
        if( ( *(imgdata + ( i-( bInfoHeader.width-1 ) ) ) ) > mayor ){  //X-629
            mayor = *(imgdata+(i-(bInfoHeader.width-1)));
        }

        if( ( *(imgdata + ( i+( bInfoHeader.width-1 ) ) ) ) > mayor ){  //X+629
            mayor = *(imgdata+(i+(bInfoHeader.width-1)));
        }
     
        if( ( *(imgdata + ( i+( bInfoHeader.width ) ) ) ) > mayor ){    //X+630
            mayor = *(imgdata+(i+(bInfoHeader.width)));
        }
        
        if( ( *(imgdata + ( i+( bInfoHeader.width+1 ) ) ) ) > mayor ){  //X+631
            mayor = *(imgdata+(i+(bInfoHeader.width+1)));
        }
        
        *(aux_img+i) = mayor ;
    }
    printf("i=%d \n",i);

    for (i=0; i < bInfoHeader.width*bInfoHeader.height;i++){
        *(imgdata+i) = *(aux_img+i) ;
    }
}


/*
   |-------------------------------------| 
   |0        1       2       3       4   |   ...... 629              primeros 630 pixeles   width
   |630     631     632     633     634  |   ...... 1259
   |1260    1261   -1262-   1263    1264 |   ...... 1889
   |1890    1891    1892    1893    1894 |   ...... 2519
   |2520    2521    2522    2523    2524 |   ...... 3149
   |-------------------------------------|
    ...
    ...
    396270  396271  396272  396273  396274  ......396899
 
buscamos el mayor de los que rodea a X y ponemos X=mayor

   |-------------------------------------------------| 
   |0          1       X-(630*2)        3        4   |   ...... 629          primeros 630 pixeles   width
   |630     X-630-1      X-630      X-630+1     634  |   ...... 1259
   |X-2       X-1          X          X+1       X+2  |   ...... 1889                -1262-
   |1890    X+630-1      X+630      X+630+1     1894 |   ...... 2519
   |2520      2521     X+(630*2)      2523      2524 |   ...... 3149
   |-------------------------------------------------|
    ...
    395640  395641  395642    395643  395644  ......    396268  396269
    396270  396271  396272    396273  396274  ......    396898  396899  
     
     X comienza en 1262 
 */


void dilata_5 ( unsigned int *imgdata , unsigned int *aux_img , bmpInfoHeader bInfoHeader)
{
    unsigned int mayor,i;          

    for (i=(bInfoHeader.width*2)+2; i < bInfoHeader.width*(bInfoHeader.height-4);i++){
        mayor = *(imgdata+i);    // este es el pixel X

        if( ( *(imgdata + ( i-( bInfoHeader.width*2 ) ) ) ) > mayor ){  //X-(630*2)
            mayor = *(imgdata+(i-(bInfoHeader.width*2)));
        }

        if( ( *(imgdata + ( i-( bInfoHeader.width+1 ) ) ) ) > mayor ){  //X-631
            mayor = *(imgdata+(i-(bInfoHeader.width+1)));
        }

        if( ( *(imgdata + ( i-( bInfoHeader.width ) ) ) ) > mayor ){    //X-630
            mayor = *(imgdata+(i-(bInfoHeader.width)));
        }
     
        if( ( *(imgdata + ( i-( bInfoHeader.width-1 ) ) ) ) > mayor ){  //X-629
            mayor = *(imgdata+(i-(bInfoHeader.width-1)));
        }

        if( ( *(imgdata + ( i-1 ) ) )  > mayor ){                       //X-1
            mayor = *(imgdata+(i-1));
        }

        if( ( *(imgdata + ( i-2 ) ) )  > mayor ){                       //X-2
            mayor = *(imgdata+(i-2));
        }

        if( ( *(imgdata + ( i+1 ) ) )  > mayor ){                       //X+1
            mayor = *(imgdata+(i+1));
        }

        if( ( *(imgdata + ( i+2 ) ) )  > mayor ){                       //X+2
            mayor = *(imgdata+(i+2));
        }
        
        if( ( *(imgdata + ( i+( bInfoHeader.width-1 ) ) ) ) > mayor ){  //X+629
            mayor = *(imgdata+(i+(bInfoHeader.width-1)));
        }
     
        if( ( *(imgdata + ( i+( bInfoHeader.width ) ) ) ) > mayor ){    //X+630
            mayor = *(imgdata+(i+(bInfoHeader.width)));
        }
        
        if( ( *(imgdata + ( i+( bInfoHeader.width+1 ) ) ) ) > mayor ){  //X+631
            mayor = *(imgdata+(i+(bInfoHeader.width+1)));
        }

        if( ( *(imgdata + ( i+( bInfoHeader.width*2 ) ) ) ) > mayor ){  //X+(630*2)
            mayor = *(imgdata+(i+(bInfoHeader.width*2)));
        }
        
        
        *(aux_img+i) = mayor ;
    }
    printf("i=%d \n",i);

    for (i=0; i < bInfoHeader.width*bInfoHeader.height;i++){
        *(imgdata+i) = *(aux_img+i) ;
    }
}
