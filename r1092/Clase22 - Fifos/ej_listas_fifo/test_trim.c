#include <stdio.h>
#include "trim.h"

int main(int argc, char **argv){
    int n;
    for(n=1; n<argc; n++){
        printf("'%s' >> ", argv[n]);
        printf("'%s'\n", trim(argv[n]));
    }
    return 0;
}