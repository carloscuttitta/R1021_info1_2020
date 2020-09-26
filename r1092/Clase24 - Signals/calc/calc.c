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
	int var1, var2;
	char op;
    signal(SIGFPE, maneja_div_x_cero);
	while(1) {
		scanf("%d %d %c", &var1, &var2, &op);
		// si las dos variables son cero, termina el programa
		if(!var1 && !var2){
			printf("bye!\n");
			break;
		}
		
		printf("%d %c %d = %d\n", var1, op, var2, operacion(var1, var2, op));
	}
	return 0;
}
