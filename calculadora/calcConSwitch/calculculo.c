#include<stdio.h>

int main (void)
{
    char    operacion;
    float   op1,op2;

    printf("Ingrese primer operando : \n");
    scanf("%f",&op1);
    printf("Ingrese segundo operando : \n");
    scanf("%f",&op2);
    getchar();
    printf("Opciones que tenés: \n");
    printf("1 - Sumar\n2 - Restar\n3 - Multiplicar\n4 - Dividir\n");
    printf("Ya te decidiste que vas a hacer???:\n ");
    operacion = getchar();
    switch (operacion)
    {
        case '1':
            printf("El resultado de tu operación fue: %.2f \n", op1 + op2);
            break;
        case '2':
            printf("El resultado de tu operación fue: %.2f \n", op1 - op2);
            break;
        case '3':
            printf("El resultado de tu operación fue: %.2f \n", op1 * op2);
            break;
        case '4':
            printf("El resultado de tu operación fue: %.2f \n", op1 / op2);
            break;
        default:
            printf("Ingrese una opción correcta\n");
            break;
    }   
    return 0;
}

