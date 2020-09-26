#include <stdio.h>

int main(void){
    int i, j, n;
    
	printf("Ingrese un numero: ");
	scanf("%d", &n);
    
    //----------------------------
    for(i=0, j=n; i<n; i++, j--){
        printf("i=%d  j=%d\n", i, j);
    }
    printf("al salir, i=%d  j=%d\n", i, j);
    
    return 0;
}
