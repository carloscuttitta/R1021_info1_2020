#include <stdio.h>
#include <string.h>

#define TAMANIO_BLOQUE	1024

#define OK				0
#define EINVOCAR		1
#define ESONIGUALES		2
#define	EOPENORIG		3
#define	EOPENDEST		4	
#define EPROCORIG		5


int main(int ac, char **av){
	FILE *fpi, *fpo;
	char buff[TAMANIO_BLOQUE];
	int leidos;

	// verificacion de los parametros de la linea de comandos
	if(ac != 3){
		printf("invocar %s <origen> <destino>\n", av[0]);
		return EINVOCAR;
	}
	if(strcmp(av[1], av[2]) == 0){
		printf("error <origen> y <destino> no pueden ser iguales\n");
		return ESONIGUALES;
	}	
	
	// abro origen de los datos a copiar
	if((fpi = fopen(av[1], "r")) == NULL){
		printf("error al abrir el origen de los datos '%s'\n", av[1]);
		return EOPENORIG;
	}
		
	// abro destino de los datos a copiar
	if((fpo = fopen(av[2], "w")) == NULL){
		printf("error al abrir el destino de los datos '%s'\n", av[2]);
		fclose(fpi);
		return EOPENDEST;
	}

	// leo del origen y escribo en el destino
	do{
		leidos = fread(buff, 1, TAMANIO_BLOQUE, fpi);
		fwrite(buff, 1, leidos, fpo);
		fflush(fpo);
	}while(leidos == TAMANIO_BLOQUE);
	
	// verifico si salio por EOF o por algun error
	if(!feof(fpi)){
		if(ferror(fpi)){
			printf("error al procesar el origen de los datos '%s'\n", av[1]);
			fclose(fpi);
			fclose(fpo);
			return EPROCORIG;
		}
	}
	fclose(fpi);
	fclose(fpo);
	return OK;
}
