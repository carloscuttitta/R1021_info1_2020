#include"my.h"


int det( int **mm , int n )
{
    int r=0,c,i,j,k,l,t,aux,otro;
    int **p;

    if(n == 2){
        r = mm[0][0]*mm[1][1] - mm[1][0]*mm[0][1];
    }else{
        for(j=0; j < n; j++){
            p = (int **)malloc(sizeof(int)*(n-1));
            for(i=0; i < ( n-1 ); i++){
                p[i] = (int *)malloc(sizeof(int)*(n-1) );
            }
            for( k=1 ; k < n ; k++){
                c = 0;
                for(l=0; l < n ; l++){
                    if(l != j){
                        p[k-1][c] = mm[k][l]; // armo matriz para determinante anterior
                        c++;
                    }
                }
            }
            otro= det(p, n-1 );
            aux = (int)pow(-1, 2+j) * mm[0][j] * otro;
            r = r + aux;
            for(t = 0; t < (n-1); t++){
                free(p[t]);
            }
            free(p);
        }
    }
    return r;
}

