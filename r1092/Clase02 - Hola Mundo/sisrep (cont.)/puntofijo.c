#include <stdio.h>

int main(void){
    int a, b, suma;
    printf("ingrese dos numeros: ");
    scanf("%d %d", &a, &b);
    suma = a+b;
    printf("%d.%d + %d.%d = %d.%d\n", a/10, a%10, b/10, b%10, 
	suma/10, suma%10);
    return 0;
}

