#include <stdio.h>
#include "calc-func.h"

int main(void){
	int var1, var2;
	char op;
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
