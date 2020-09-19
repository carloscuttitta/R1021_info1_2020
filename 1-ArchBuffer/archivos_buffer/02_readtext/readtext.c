#include <stdio.h>

#define TAM 10

int main(int ac, char **av){
	FILE *fp;
	char s[100];
	
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
	
	// leo el contenido del archivo linea por linea
//Declaración: char * fgets ( char * cadena, int tamaño, FILE * fichero);
//Lee hasta encontrar un avance de línea o alcanzar la longitud máxima que se ha indicado
	while(fgets(s, TAM, fp) != NULL){
		printf("%s", s);
	}

	fclose(fp); 

	return 0;
}

