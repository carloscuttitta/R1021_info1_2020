#include <stdio.h>

int main(void){
    int i, n;
    
	printf("Ingrese un numero: ");
	scanf("%d", &n);
    
    //- pares --------------------
    for(i=0; i<n; i++){
        if(i%2 == 0){
            printf("i=%d\n", i);
        }
    }
    
    //----------------------------
    printf("*****************\n");
    
    //- impares ------------------
    for(i=0; i<n; i++){
        if(i%2 == 0){
            continue;
        }
        printf("i=%d\n", i);
    }
    
    return 0;
}
