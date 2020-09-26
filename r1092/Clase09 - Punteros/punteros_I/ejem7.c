#include <stdio.h>
#include <string.h>

#define SIZE 100

char *mi_strcat(char *s1, char *s2);

int main(void){
    char b[SIZE];

    strcpy(b, "hola ");
    printf("%s\n", b);
    printf("%s\n", mi_strcat(b, "chau"));

    return 0;
}

char *mi_strcat(char *s1, char *s2){
    char *p;
    p = s1 + strlen(s1);
    strcpy(p, s2);
    return s1;
}











