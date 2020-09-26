#include <stdio.h>

int f(int x);
int g(int y);

// --------------------------------------------------
int main(void){
    int a;
    
    a = 5;
    printf("(antes de llamar a f()) a = %d\n", a);
    a = f(a);
    
    printf("(despues de llamar a f()) a = %d\n", a);
    
    g(a);
    printf("(despues de llamar a g() sin asignar el valor de retorno) a = %d\n", a);
    
    a = g(a);
    printf("(despues de llamar a g() asignando el valor de retorno) a = %d\n", a);
    
    return 0;
}

// --------------------------------------------------
int f(int x){
    x++;
    return x;
}

// --------------------------------------------------
int g(int y){
    return y-5;
}

