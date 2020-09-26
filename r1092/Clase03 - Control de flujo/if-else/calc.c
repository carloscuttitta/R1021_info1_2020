#include <stdio.h>

int main(void){
    int a, b;
    char op;
    int res;

    scanf("%d %d %c", &a, &b, &op);
    // si las dos variables son cero, termina el programa
    if(!a && !b){
    	printf("Nada para hacer. bye!\n");
	    return 1;
    }
    // ------------------------------------------------------
    if(op == '+'){      // suma
        res = a + b;
    }
    else if(op == '-'){ // resta
        res = a - b;
    }
    else if(op == '*'){ // multiplicacion
        res = a * b;
    }
    else if(op == '/'){ // division
        if(!b){
            printf("Error. Imposible dividir por cero.\n");
            return 2;
        }
        res = a / b;
    }
    else if(op == '%'){ // modulo
        if(!b){
            printf("Error. Imposible dividir por cero.\n");
            return 2;
        }
        res = a % b;
    }
    else{
        printf("Error. Operacion '%c' no permitida.\n", op);
        return 3;
    }

    // ------------------------------------------------------
    printf("%d %c %d = %d\n", a, op, b, res);
    return 0;
}

