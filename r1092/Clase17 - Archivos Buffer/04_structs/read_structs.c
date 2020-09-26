#include <stdio.h>

struct data {
	int id;
	char msg[20];
	};

int main(int ac, char **av){
	FILE *fp;
	struct data d;

	
	// verifico argumentos de la linea de comandos
	if(ac != 2){
		printf("ERROR! Invocar %s <archivo_de_donde_leer>\n", av[0]);
		return 1;
	}
	
	// abro el archivo
	if((fp = fopen(av[1], "r")) == NULL){
		printf("ERROR! No pude abrir %s", av[1]);
		return 2;
	}
	
	// leo del disco
	fread((char*)&d, sizeof(struct data), 1, fp);
	
	//imprimo los datos
	printf("id=%d   msg=%s\n", d.id, d.msg);
		
	// cierro el archivo
	fclose(fp);
	
	return 0;
}
