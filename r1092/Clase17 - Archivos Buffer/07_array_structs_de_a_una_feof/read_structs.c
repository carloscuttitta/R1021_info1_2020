#include <stdio.h>
#include <stdlib.h>

struct data {
	int id;
	char msg[20];
	};


int main(int ac, char **av){
	FILE *fp;
	struct data *ps;
	
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
	
	// reservo memoria para alocar una estructura data
	ps = (struct data *)malloc(sizeof(struct data));

	// leo del disco e imprimo los datos
	while(1){
		fread((char*)ps, sizeof(struct data), 1, fp);
		if(feof(fp))
			break;
		printf("id=%d   msg=%s\n", ps->id, ps->msg);
	}
		
	// libero la estructura
	free(ps);
	
	// cierro el archivo
	fclose(fp);
	
	return 0;
}
