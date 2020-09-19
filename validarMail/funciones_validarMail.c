#include"my.h"

void my_toupper (char * p)
{
    int i;
    for ( i=0 ; *(p+i) != '\0' ; i++ ){
        if ( (*(p+i) >= 'a') && (*(p+i) <= 'z') ){
            *(p+i) = *(p+i) - ' ';
        }
    }
}

int validar_correo ( char * vec )
{
    int i,j=0,r=0;

    for ( i=0 ; *(vec+i) != '\0' ; i++ ){
        if ( ( (*(vec+i) >= '@') && (*(vec+i) <= 'Z') ) 
            || ( (*(vec+i) >= '0') && (*(vec+i) <= '9') )
            || (*(vec+i) == '.')
            || (*(vec+i) == '_')
            || (*(vec+i) == '-') )
        {
            if (*(vec+i) == '@'){
                j++;
                if (j !=1){
                    r = 1;
                }
            }
        }else{
            r = 1;
        }   
    }
    return r;
}    
        
        
int imprimirNombre(char *p)
{
    int     i;
    char    *q,r=0;
    
    for( i=0; *(p+i) != '@' ; i++ ){    // cuento cuanto hay antes de @
    }
    q=(char *)malloc(i * sizeof(char));
    if ( q != NULL )
    {
        for( i=0; *(p+i) != '@' ; i++ )
        {    
            *(q+i) = *(p+i);
        }
        *(q+i) = '\0';
        printf("El mail es : %s  \n",q);

        free(q);
    }else
    {
        r=1;
    }

    return r;
}        
        
        
int imprimirDominio(char *p)
{
    int     i=0,j=0,r=0;
    char    *q;
    
    for( i=0; *(p+i) != '\0' ; i++ )
    {    
        if ( *(p+i) == '@' )
        {
            j=i;
        }
    }
    q=(char *)malloc( (i-j) * sizeof(char));
    if ( q != NULL )
    {
        i=0;
        while( *(p+j) != '\0' )
        {    
            *(q+i) = *(p+j+1);
            i++;
            j++;
        }
        *(q+i) = '\0';
        printf("El dominio es : %s  \n",q);
        free(q);
    }else
    {
        r=1;
    }

    return r;
}        
        
        
        
        
        
        
        
        
        
        
        
        
    

