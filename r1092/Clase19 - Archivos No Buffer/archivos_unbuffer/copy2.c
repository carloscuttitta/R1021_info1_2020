#include <stdio.h>
#include <string.h>		// strcmp, strerror
#include <sys/types.h>	// open, fstat 
#include <sys/stat.h>	// open, fstat
#include <fcntl.h>		// open
#include <errno.h>		// perror
#include <unistd.h>		// fstat, read, write, close 

#define TAMANIO_BLOQUE	1024

#define OK				0
#define EINVOCAR		1
#define ESONIGUALES		2
#define	EOPENORIG		3
#define	EOPENDEST		4	
#define EPROCORIG		5
#define ESTATORIG		6

int main(int ac, char **av){
	int fdi, fdo;
	char buff[TAMANIO_BLOQUE];
	int leidos;
	struct stat st;

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
	if((fdi = open(av[1], O_RDONLY)) == -1){
		printf("error al abrir el origen de los datos '%s'\n", av[1]);
		perror(strerror(errno));
		return EOPENORIG;
	}
		
	// leo los permisos del origen para hacer que el destino tenga los mismos
	if(fstat(fdi, &st) == -1){
		printf("error al obtener los permisos del destino de los datos '%s'\n", av[2]);
		perror(strerror(errno));
		close(fdi);
		return ESTATORIG;
	}
		
	// abro destino de los datos a copiar
	if((fdo = open(av[2], O_WRONLY|O_CREAT|O_TRUNC, st.st_mode)) == -1){
		printf("error al abrir el destino de los datos '%s'\n", av[2]);
		perror(strerror(errno));
		close(fdi);
		return EOPENDEST;
	}

	// leo del origen y escribo en el destino
	do{
		leidos = read(fdi, buff, TAMANIO_BLOQUE);
		write(fdo, buff, leidos);
	}while(leidos == TAMANIO_BLOQUE);
	 	
	// verifico si salio por EOF o por algun error
	if(leidos != 0){
		if(leidos == -1){
			printf("error al procesar el origen de los datos '%s'\n", av[1]);
			perror(strerror(errno));
			close(fdi);
			close(fdo);
			return EPROCORIG;
		}
	}
	close(fdi);
	close(fdo);
	return OK;
}
