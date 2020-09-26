#include <stdio.h>

int f(int x);

// --------------------------------------------------
int main(void){
    int a;
    
    a = 5;
    printf("(antes de llamar a f()) a = %d\n", a);
    
    a = f(a);
    printf("(despues de llamar a f()) a = %d\n", a);
    
    return 0;
}

// --------------------------------------------------
int f(int x){
    x++;
    return x;
}

