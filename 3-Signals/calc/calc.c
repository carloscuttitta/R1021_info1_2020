#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "calc-func.h"

// -----------------------------------------------------------------------------
void maneja_div_x_cero(int sig){
    printf("Epa! dividiste por cero!!!\n");
    exit(ERR_ZERO);
}

// -----------------------------------------------------------------------------
int main(void){
    int var1, var2,sale=1;
    char op;
        
    signal(SIGFPE, maneja_div_x_cero);  //The SIGFPE signal para un error aritmetico fatal
	
    while(sale) {
        printf("ingrese los dos numeros y el operando, para salir ingreso 2 ceros\n");
        scanf("%d %d %c", &var1, &var2, &op);
        if(!var1 && !var2){
            printf("bye!\n");
            sale = 0;
        }
		
        printf("%d %c %d = %d\n", var1, op, var2, operacion(var1, var2, op));
    }
    return 0;
}
