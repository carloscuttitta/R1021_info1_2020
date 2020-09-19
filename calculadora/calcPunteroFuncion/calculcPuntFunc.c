#include<stdio.h>

float sumar (float , float );
float restar (float , float );
float multiplicar (float , float );
float dividir (float , float );

int main (void)
{
    char operacion;
    float (* quehago[]) (float, float) = {sumar, restar, multiplicar, dividir};
    float op1,op2;

    printf("Ingrese primer operando : \n");
    scanf("%f",&op1);

    printf("Ingrese segundo operando : \n");
    scanf("%f",&op2);

    printf("Opciones que tenés: \n");
    printf("1 - Sumar\n2 - Restar\n3 - Multiplicar\n4 - Dividir\n");
    printf("Ya te decidiste que vas a hacer???:\n ");
    
    getchar();                      // limpio el buffer del teclado
    operacion = getchar();
    if ((operacion >= '1') && (operacion <= '4'))
    {
        printf("El resultado de tu operación fue: %.2f \n", quehago[operacion-'1'] (op1, op2));
    }    
    else 
    {
        printf("\nVos sos papanata, era de 1 a 4!!!!!!\n\n");
    }
   return 0;
}


float sumar (float op1, float op2)
{
        return op1+op2;
}


float restar (float op1, float op2)
{
        return op1-op2;
}


float multiplicar (float op1, float op2)
{
        return op1*op2;
}


float dividir (float op1, float op2)
{
        return op1/op2;
}

