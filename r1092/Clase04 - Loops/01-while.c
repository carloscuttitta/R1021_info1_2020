#include <stdio.h>

#define MAX 10

int main(void){
    int i=0;
    
    while(i<MAX){
        printf("i=%d\n", i);
        i++;
    }
    printf("al salir, i=%d\n", i);
    
    //----------------------------
    while(i){
        printf("i=%d\n", i);
        i--;
    }
    printf("al salir, i=%d\n", i);
    
    return 0;
}
