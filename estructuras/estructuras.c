
#include <stdio.h>
#include <stdlib.h>

int main (void)
{

  
    
struct datos_t {
        int     numero;
        char    caracter;
        float   real;
        char    v[10];
    };

typedef struct {
        int     numero;
        float   real;
        char    caracter;
        char    v[10];
    }data_t;

typedef struct {
        char    caracter;
        int     numero;
        char    v[10];
        float   real;
        short   chico;
    }d_t;
    
    struct datos_t n;
    data_t *n1;
    d_t n2;
    
    n1= (data_t *)malloc(sizeof(data_t));
    
    n.numero=10;
    n.caracter='a';
    n.real=3.14;
    n.v[2]='0';

    n1->numero=20;
    n1->caracter='b';
    n1->real=2.71;
    n1->v[2]='1';
    
    n2.numero=20;
    n2.caracter='b';
    n2.real=2.71;
    n2.chico=30;
    
    
    printf("numero\t%p  numero\t%d\t\tsize int %ld\n",&n.numero,n.numero,sizeof(int));
    printf("char\t%p  char\t%c\t\tsize char %ld\n",&n.caracter,n.caracter,sizeof(char));
    printf("real\t%p  real\t%0.2f\t\tsize float %ld\n",&n.real,n.real,sizeof(float));
    printf("vector\t%p  vector\t%c\t\tsize vector %ld\n",&n.v[2],n.v[2],sizeof(n.v));
    
    printf("size\t%ld\n",sizeof(n));
    printf("\n");
    
    printf("numero\t%p  numero\t%d\t\tsize int %ld\n",&n1->numero,n1->numero,sizeof(int));
    printf("real\t%p  real\t%0.2f\t\tsize float %ld\n",&n1->real,n1->real,sizeof(float));
    printf("char\t%p  char\t%c\t\tsize char %ld\n",&n1->caracter,n1->caracter,sizeof(char));
    printf("vector\t%p  vector\t%c\t\tsize vector %ld\n",&n1->v[2],n1->v[2],sizeof(n1->v));
    
    printf("size\t%ld\n",sizeof(n1));
    printf("\n");

    printf("numero\t%p  numero\t%d\t\tsize int %ld\n",&n2.numero,n2.numero,sizeof(int));
    printf("real\t%p  real\t%0.2f\t\tsize float %ld\n",&n2.real,n2.real,sizeof(float));
    printf("char\t%p  char\t%c\t\tsize char %ld\n",&n2.caracter,n2.caracter,sizeof(char));
    printf("vector\t%p  vector\t%c\t\tsize vector %ld\n",&n2.v[2],n2.v[2],sizeof(n2.v));
    printf("chico\t%p  chico\t%d\t\tsize short %ld\n",&n2.chico,n2.chico,sizeof(short));
    
    printf("size\t%ld\n",sizeof(n2));
    printf("\n");
    
    return (0);
}
