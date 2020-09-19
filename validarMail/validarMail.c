#include"my.h"

int main (int argc , char ** argv)
{
    int     valido;
    
    if (argc == 2)
    {
        my_toupper(*(argv+1) );
        valido = validar_correo( *(argv+1) );    
        if ( valido == 0 )
        {
            valido=imprimirNombre(*(argv+1));
            if (valido !=0)
            {
                printf("error asignando memoria\n");
            }
            valido=imprimirDominio(*(argv+1));
            if (valido !=0)
            {
                printf("error asignando memoria\n");
            }
        }
        else
        {
            printf("%s  NO es un mail \n",*(argv+1));
        }
    }else
    {
        printf("escriba un solo argumento que sea un mail\n");
    }
    return 0;
}


        
        
        
        
        
        
    

