#include<stdio.h>

int main (int argc , char ** argv)
{
    int     i,j ;
    char * p;

    printf("\n");
    printf("primer ejemplo\n");
    printf("%d es argc\n",argc);
    for ( i=1 ; i<argc ; i++ )
    {
        printf("%s \t" , *(argv+i) );           // argv[i]
    }
    printf("\n");
    
    for(j=1 ; j < argc ; j++)
    {
        p = *(argv+j);
    
        for (i=0 ; *(p+i) != '\0' ; i++)
        {
            if ( *(p+i) == 'e')
            {
                *(p+i) = '*';
            }
            printf("%c \t" ,*(p+i)  );
        }
        printf("\n");
    }
}
