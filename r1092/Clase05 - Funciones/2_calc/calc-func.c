#include <stdlib.h>
#include <stdio.h>
#include "calc-func.h"

int operacion(int a, int b, char op) {
	int res;
	switch(op){
		case SUMA:
			res = a + b;
			break;
		case RESTA:
			res = a - b;
			break;
		case MULTIPLICACION:
			res = a * b;
			break;	
		case DIVISION:
			if(!b) {
			    printf("Error! Division por cero\n");
				exit(ERR_ZERO);			
			}
			res = a / b;
			break;
		case MODULO:
			if(!b) {
			    printf("Error! Division por cero\n");
				exit(ERR_ZERO);			
			}
			res = a % b;
			break;			
		default:
			    printf("Error! Operacion invalida\n");
			exit(ERR_INVALID);
			break;
	}
	return res;
}
