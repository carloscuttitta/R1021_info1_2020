#include <stdio.h>
#include <stdlib.h> // malloc
#include <string.h> // strlen, strcpy
#include <ctype.h>  // toupper

char *str_toupper(char *);

int main(int ac, char **av){
    int n;
    char *p;
    
    if(ac < 2){
        printf("Error! Se debe pasar por lo menos un argumento\n");
        return 1;
    }

    for(n=1; n<ac; n++){
        p = (char*)malloc(strlen(av[n] + 1));
        strcpy(p, av[n]);
        p = str_toupper(p);
        printf("av[%d]:\"%s\", p:\"%s\"\n", n, av[n], p);
        free(p);
    }

    return 0;
}

char *str_toupper(char *s){
    char *p = s;
    for(; *s; s++)
        *s = toupper(*s);
    return p;
}
