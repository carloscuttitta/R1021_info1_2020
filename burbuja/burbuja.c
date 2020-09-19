// compilar gcc -c burbuja.c -o burbuja.o -Wall
// linkear  gcc  burbuja.o -o burbuja -Wall

#include <stdio.h>
#define CANT	6


void imprimir(int *p,int n);

int main (void)
{

int aux,resto,i,flag,vInt[CANT]={2,286,9,59,928,3};


  imprimir(&vInt[0],CANT);
  resto=0;
  do
  {
    resto++;
    flag=0;
    for(i=0;i < (CANT-resto);i++)
    {
      if(vInt[i] > vInt[i+1])
      {
	aux=vInt[i];
	vInt[i]=vInt[i+1];
	vInt[i+1]=aux;
	flag=1;
      }
    }  
  }while(flag);
  imprimir(&vInt[0],CANT);
  
  return (0);
}

void imprimir( int*p,int n)
{
  int j;
  printf("\n");
  for(j=0;j<n;j++)
  {
    printf("%d \t",*(p+j));
  }
  printf("\n");
}

  
