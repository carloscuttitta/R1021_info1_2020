#include <stdio.h>

int strlen1(char *s);
int strlen2(char *s);

int main(void){
    char mensaje1[] = "hola mundo";
    char *mensaje2 = "aca estoy";

    printf("... usando strlen1\n");
    printf("%s. longitud=%d\n", mensaje1, strlen1(mensaje1));
    printf("%s. longitud=%d\n", mensaje2, strlen1(mensaje2));

    printf("... usando strlen2\n");
    printf("%s. longitud=%d\n", mensaje1, strlen2(mensaje1));
    printf("%s. longitud=%d\n", mensaje2, strlen2(mensaje2));

    return 0;
}

int strlen1(char *s){
    int n;
    for(n=0; *s!='\0'; n++, s++)
        ;
    return n;
}

int strlen2(char *s){
    char *p = s;
    while(*p != '\0')
        p++;
    return p-s;
}















