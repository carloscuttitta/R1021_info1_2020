#include <stdio.h>

int main(void){
    int i, n;
    
	printf("Ingrese un numero: ");
	scanf("%d", &n);
    
    //----------------------------
    for(i=0; i<n; i++){
        printf("i=%d\n", i);
    }
    printf("al salir, i=%d\n", i);
    
    //----------------------------
    for(i=n; i>0; i--){
        printf("i=%d\n", i);
    }
    printf("al salir, i=%d\n", i);
    
    return 0;
}
