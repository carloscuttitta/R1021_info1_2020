#include <stdio.h>

int main(void){
    int i=0;
    int n;
    
	printf("Ingrese un numero: ");
	scanf("%d", &n);
    
    //----------------------------
    do{
        printf("i=%d\n", i);
        i++;
    }while(i<n);
    printf("al salir, i=%d\n", i);
    
    //----------------------------
    do{
        printf("i=%d\n", i);
        i--;
    }while(i);
    printf("al salir, i=%d\n", i);
    
    return 0;
}
