#include <stdio.h>

int f(int a);

// --------------------------------------------------
int main(void){
    int a;
    
    a = 5;
    printf("(antes de llamar a f()) a = %d\n", a);
    
    f(a);
    printf("(despues de llamar a f()) a = %d\n", a);
    
    return 0;
}

// --------------------------------------------------
int f(int a){
    a++;
    return a;
}
