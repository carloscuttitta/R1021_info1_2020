#include "string.h"
#include "trim.h"

char *ltrim(char *s){
    char *p;
    for(p=s; *p==' '; p++)
        ;
    return p;
}

char *rtrim(char *s){
    char *p;
    for(p=&s[strlen(s)-1]; *p==' '; p--)
        ;
    *(p+1) = '\0';
    return s;
}

char *trim(char *s){
    return ltrim(rtrim(s));
}

