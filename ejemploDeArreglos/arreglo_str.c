// compilar gcc -c arreglo_str.c -o arreglo_str.o -Wall
// linkear  gcc  arreglo_str.o -o main

#include<stdio.h>

void imprimir_nombres (char ** vec);
void imprimir_caracteres (char * vec);


int main (void)
{
    char * arr[3]={"pepe" , "jose" , "carlos"};
    int i,j;
    char *p;
    

    printf("\n");
    printf("primer ejemplo\n");
    for ( i=0;i<3;i++)
    {
        printf("%s \t",*(arr+i));
    }

    printf("\n\n");
    printf("segundo  ejemplo\n");
    for ( i=0;i<3;i++)
    {
        printf("%s \t",arr[i]);
    }

    printf("\n\n");
    printf("primer ejemplo pero de a caracteres\n");
    for (j=0;j<3;j++)
    {
        p = *(arr+j);

        for ( i=0;*(p+i) != '\0';i++)
        {
            printf("%c ",*(p+i));
        }
        printf("\t");
    }

    printf("\n\n");
    printf("primer ejemplo para imprimir nombres con una funcion\n");
    
    imprimir_nombres(&arr[0]);    

    printf("\n");
    printf("segundo ejemplo para imprimir nombres de a caracteres con una funcion\n");
    for (i=0;i<3;i++)
    {
        imprimir_caracteres(*(arr+i));    //  arr[i]   argv[i]
    }
    printf("\n");
    
    return 0;
}



void imprimir_nombres (char ** vec)
{
    int i;
    for ( i=0;i<3;i++)
    {
        printf("%s \t",*(vec+i));
    }
    printf("\n");
}    

void imprimir_caracteres (char * vec)
{
    int i;
    for ( i=0;*(vec+i) != '\0';i++)
    {
        printf("%c ",*(vec+i));
    }
    printf("\t");
}    
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    

