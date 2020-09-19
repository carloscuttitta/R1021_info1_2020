//  compilar gcc -c argumentos_main.c -o argumentos_main.o -Wall
//  linkear  gcc  argumentos_main.o -o main

//  ejecutar ./main nacho carlos pedro hector      

#include<stdio.h>

void imprimir_nombres (int , char ** );
void imprimir_caracteres (char * );

int main (int argc , char ** argv)
{
    int     i , j;
    char    *p;

    printf("\n");
    printf("primer ejemplo\n");
    printf("%d es argc\n",argc);
    for ( i=1 ; i<argc ; i++ )
    {
        printf("%s \t" , *(argv+i) );
    }


    printf("\n\n");
    printf("segundo  ejemplo\n");
    for ( i=1 ; i<argc ; i++ )
    {
        printf("%s \t" , argv[i] );
    }


    printf("\n\n");
    printf("primer ejemplo pero de a caracteres\n");
    for ( j=0 ; j<argc ; j++ )
    {
        p = *(argv+j);

        for ( i=0 ; *( p+i ) != '\0' ; i++ )
        {
            printf("%c " , *( p+i ) );
        }
        printf("\t");
    }


    printf("\n\n");
    printf("segundo ejemplo pero de a caracteres mas dificil de ver\n");
    for ( j=1 ; j<argc ; j++ )
    {
        for ( i=0 ; *( *(argv+j) + i ) != '\0' ; i++ )
        {
            printf("%c " , *( *(argv+j) + i ) );
        }
        printf("\t");
    }
    
    printf("\n\n");
    printf("primer ejemplo para imprimir nombres con una funcion\n");
    imprimir_nombres( argc , argv );    

    printf("\n");
    printf("segundo ejemplo para imprimir nombres de caracteres con funcion\n");
    for ( i=1 ; i<argc ; i++ )
    {
        imprimir_caracteres( *(argv+i) );    
    }
    printf("\n");
    
    return 0;
}







void imprimir_nombres (int cant_string , char **vec)
{
    int i;

    for ( i=1 ; i<cant_string ; i++ )
    {
        printf("%s \t" , *(vec+i) );
    }
    printf("\n");
}    

void imprimir_caracteres ( char * p )
{
    int i;

    for ( i=0 ; *(p+i) != '\0' ; i++ )
    {
        printf("%c " , *(p+i) );
    }
    printf("\t");
}    
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    

