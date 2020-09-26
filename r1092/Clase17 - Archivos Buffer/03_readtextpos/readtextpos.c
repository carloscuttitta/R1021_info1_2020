#include <stdio.h>
#include <string.h> //por strerror()

int main(int ac, char **av){
	FILE *fp;
	char s[100];
	int i;

	// verifico argumentos de la linea de comandos
	if(ac != 2){
		printf("ERROR! Invocar %s <archivo_a_leer>\n", av[0]);
		return 1;
	}
	
	// abro el archivo
	if((fp = fopen(av[1], "r")) == NULL){
		printf("ERROR! No pude abrir %s", av[1]);
		return 2;
	}
	
	// -------------------------------------------------------
	// me muevo 30 bytes desde el comienzo del archivo
	if((i = fseek(fp, 30, SEEK_SET)) == -1){
		printf("%s\n", strerror(i));
		return 3;
	}
	printf("posicion = %ld\n", ftell(fp));

	// leo 50 bytes desde la posicion 30
	i = fread(s, 1, 50, fp);
	printf("leidos = %d bytes\n", i);
	printf("posicion = %ld\n", ftell(fp));

	// los saco por pantalla
	fwrite(s, 1, 50, stdout);
	puts("\n---------------------------------------------\n");	

	// -------------------------------------------------------
	// me muevo 20 bytes desde la posicion actual
	if((i = fseek(fp, 20, SEEK_CUR)) == -1){
		printf("%s\n", strerror(i));
		return 3;
	}
	printf("posicion = %ld\n", ftell(fp));
	
	// leo 50 bytes desde la posicion corriente
	i = fread(s, 1, 50, fp);
	printf("leidos = %d bytes\n", i);
	printf("posicion = %ld\n", ftell(fp));
	
	// los saco por pantalla
	fwrite(s, 1, 50, stdout);
	puts("\n---------------------------------------------\n");	
	

	// -------------------------------------------------------
	// me muevo 50 bytes desde el final del archivo para atras
	if((i = fseek(fp, -50, SEEK_END)) == -1){
		printf("%s\n", strerror(i));
		return 3;
	}
	printf("posicion = %ld\n", ftell(fp));
	
	// leo 50 bytes desde la posicion corriente
	i = fread(s, 1, 50, fp);
	printf("leidos = %d bytes\n", i);
	printf("posicion = %ld\n", ftell(fp));
	
	// los saco por pantalla
	fwrite(s, 1, 50, stdout);
	puts("\n---------------------------------------------\n");	

	// cierro el archivo
	fclose(fp); 

	return 0;
}

