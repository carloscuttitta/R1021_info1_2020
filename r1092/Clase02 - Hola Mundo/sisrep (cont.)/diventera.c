#include <stdio.h>

int main(void){
    int a, b;
    printf("ingrese dos numeros: ");
    scanf("%d %d", &a, &b);
    printf("%d / %d = %d y el resto es %d\n", a, b, a/b, a%b);
    return 0;
}

