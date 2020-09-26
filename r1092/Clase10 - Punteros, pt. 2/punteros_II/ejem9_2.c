#include <stdio.h>

char *month_name(int n);

int main(void){
    int i;

    printf("ingrese el mes: ");
    scanf("%d", &i);
    printf("... el mes ingresado es %s\n", month_name(i));

    return 0;
}

char *month_name(int n){
    char *names[] = {"invalido", "Enero", "Febrero", "Marzo",
                     "Abril", "Mayo", "Junio", "Julio",
                     "Agosto", "Septiembre", "Octubre",
                     "Noviembre", "Diciembre"};
    return ((n<1) || (n>12)) ? names[0] : names[n];
}



