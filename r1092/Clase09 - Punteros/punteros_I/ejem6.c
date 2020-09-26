#include <stdio.h>

#define SIZE 100

void strcpy0(char *d, char *s);
void strcpy1(char *d, char *s);
void strcpy2(char *d, char *s);
void strcpy3(char *d, char *s);

int main(void){
    char b[SIZE];

    strcpy0(b, "copio usando strcpy");
    printf("%s\n", b);

    strcpy1(b, "copio usando strcpy1");
    printf("%s\n", b);

    strcpy2(b, "copio usando strcpy2");
    printf("%s\n", b);

    strcpy3(b, "copio usando strcpy3");
    printf("%s\n", b);

    return 0;
}

// strcpy. version 0 usando subindices
void strcpy0(char *d, char *s){
    int i=0;
    while((d[i] = s[i]) != '\0')
        i++;
}

// strcpy. version 1 usando punteros
void strcpy1(char *d, char *s){
    while((*d = *s) != '\0'){
        s++;
        d++;
    }
}

// strcpy. version 2 usando punteros
void strcpy2(char *d, char *s){
    while((*d++ = *s++) != '\0')
        ;
}

// strcpy. version 3 usando punteros
void strcpy3(char *d, char *s){
    while((*d++ = *s++))
        ;
}

