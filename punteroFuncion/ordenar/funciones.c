void bombom (int * Datos, int cant)
{
    int i, j, auxiliar, marca;
    i = 0;
    do
    {
        marca = 0;
        for ( j = 0 ; j < cant - 1 - i; j++ )
        {
            if (Datos[ j ] > Datos[ j + 1])
            {
                auxiliar = Datos[j+1];
                Datos[j+1] = Datos[j];
                Datos[j] = auxiliar;  
                marca = 1;
            }
        }
        i++;
    }
    while ( marca );
    return;
}    
           
void bellota (int * Datos, int cant, int (*orden) (int, int) )
{
    int i, j, auxiliar, marca;
    i = 0;
    do
    {
        marca = 0;
        for ( j = 0 ; j < cant - 1 - i; j++ )
        {
  //          if (Datos[ j ] > Datos[ j + 1])
              if ( orden (Datos[ j ],Datos[ j + 1]) )
            {
                auxiliar = Datos[j+1];
                Datos[j+1] = Datos[j];
                Datos[j] = auxiliar;  
                marca = 1;
            }
        }
        i++;
    }
    while ( marca );
    return;
}    

int mayor (int a, int b)
{
    int res = 0;
    if (a>b) res = 1;
    return res;
}

int menor (int a, int b)
{
    int res = 0;
    if (a<b) res = 1;
    return res;
}
