#include <stdio.h>

int main(void){
    int i=0;
    int n;
    
	printf("Ingrese un numero: ");
	scanf("%d", &n);
    
    //----------------------------
    while(i<n){
        printf("i=%d\n", i);
        i++;
    }
    printf("al salir, i=%d\n", i);
    
    //----------------------------
    while(i){
        printf("i=%d\n", i);
        i--;
    }
    printf("al salir, i=%d\n", i);
    
    return 0;
}
