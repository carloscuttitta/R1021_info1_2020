#include <stdio.h>

#define SIZE 5


int main(void){
    int x=1, y=2, z[SIZE]={0}, *pi;

    printf("x=%d y=%d\n", x, y);

    pi = &x;    // pi apunta a x
    y = *pi;    // ahora y=x
    printf("x=%d y=%d\n", x, y);

    *pi = 0;    // ahora x=0
    printf("x=%d y=%d\n", x, y);

    pi = z;     // pi apunta al comienzo de z. Es lo mismo que hacer pi=&z[0]
    *pi = (*pi) + 3;
    printf("z[0]=%d *pi=%d\n", z[0], *pi);

    *pi += 2;
    printf("z[0]=%d *pi=%d\n", z[0], *pi);

    ++(*pi);
    printf("z[0]=%d *pi=%d\n", z[0], *pi);

    (*pi)++;
    printf("z[0]=%d *pi=%d\n", z[0], *pi);

    return  0;
}


