#include <stdio.h>
#include <string.h>

#define TAMANIO_BLOQUE	10

#define OK		0
#define EINVOCAR	1
#define ESONIGUALES	2
#define	EOPENORIG	3
#define	EOPENDEST	4	
#define EPROCORIG	5


int main(int argc, char **argv)
{
    FILE *fpin, *fpout;
    char buff[TAMANIO_BLOQUE];
    int leidos;

// verificacion de los parametros de la linea de comandos
    if(argc != 3)
    {
	printf("invocar %s <origen> <destino>\n", argv[0]);
	return EINVOCAR;
    }
    if(strcmp(argv[1], argv[2]) == 0)
    {
	printf("error <origen> y <destino> no pueden ser iguales\n");
	return ESONIGUALES;
    }	
	
// abro origen de los datos a copiar
    if((fpin = fopen(argv[1], "r")) == NULL)
    {
        printf("error al abrir el origen de los datos '%s'\n", argv[1]);
        return EOPENORIG;
    }
		
// abro destino de los datos a copiar
    if((fpout = fopen(argv[2], "w")) == NULL)
    {
	printf("error al abrir el destino de los datos '%s'\n", argv[2]);
	fclose(fpin);
	return EOPENDEST;
    }

// leo del origen y escribo en el destino
    do{
	leidos = fread(buff, 1, TAMANIO_BLOQUE, fpin);
        printf("leidos: %d\n", leidos);
	fwrite(buff, 1, leidos, fpout);
	fflush(fpout);
    }while(leidos == TAMANIO_BLOQUE);
	
// verifico si salio por EOF o por algun error
    if(!feof(fpin))
    {
	if(ferror(fpin))
        {
            printf("error al procesar el origen de los datos '%s'\n", argv[1]);
            fclose(fpin);
            fclose(fpout);
            return EPROCORIG;
	}
    }
    fclose(fpin);
    fclose(fpout);
    return OK;
}
