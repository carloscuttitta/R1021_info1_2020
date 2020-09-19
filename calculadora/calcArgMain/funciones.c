#include"my.h"

void verificarComa(int * vec , char *p)
{
    int i,j=0,NoNumero=0,negativo=0;

    *(vec+0) = 0;
    *(vec+1) = 0;
    *(vec+2) = 0;    // lo inicializo como positivo

    for (i=0 ; *(p+i) != '\0' ; i++){
        if( ((*(p+i) >= '0') && (*(p+i) <= '9')) || (*(p+i) == ',') ){
            *(vec+1)= *(vec+1)+1;
            if (*(p+i) == ','){
                j++;
                *(vec+1)=0;
                *(vec+0)=i;
            }
        }else{
            if ( (i == 0) && ( *(p+0) == '-' ) )
            {
                negativo  = 1;          // indica que es negativo    
            }else{
                NoNumero = 1;           // indica que no es un numero
            }
        }
    }
    if( ( j>1 ) || ( NoNumero == 1) ){   // caso donde hay mas de una coma o haya letras
        *(vec+0) = -1;
    }
    if ( (j==0) && ( NoNumero !=1) ){    // caso donde no tiene coma
        *(vec+0) = i;
        *(vec+1) =0;
    }
    if ( negativo == 1 ){
        *(vec+2) =1;                    // informo que es negativo
    }        
}




float myAtof(int * vect , char * p)
{
    float r=0;
    int i,j=0;
    
    if ( *(vect + 2) == 1 ){
        *(vect+0) = *(vect+0) -1;       // si es negativo le resto el lugar que ocupa el signo  
        j = 1;                          // para que no tome el signo
    }
    for (i=*(vect + 0) ; i>0 ; i--,j++){
        r = r +( (*(p+j)-'0')*pow(10,(i-1)) );
    }
    
    if (*(vect+1) != 0){     // solo lo hago si hay coma
        j=*(vect+0) +1;
        if (*(vect + 2) ==1){       // si es negativo corro 2 lugares el indicador "j"
            j=*(vect+0) +2;
        }
        for (i=1 ; *(p+j) != '\0' ; i++,j++){
            r = r +( (*(p+j)-'0')*pow(10,-i) );
        }
    }
    if ( *(vect+2) == 1 ){
        r = -r;
    }
    return r;    
}

