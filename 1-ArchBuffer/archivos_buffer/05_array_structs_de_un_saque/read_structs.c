#include <stdio.h>

struct data {
	int id;
	char msg[20];
	};

#define CSTRUCTS 5

int main(int ac, char **av){
	FILE *fp;
	struct data d[CSTRUCTS];
	int i;
	
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
	fread((char*)&d, sizeof(struct data), CSTRUCTS, fp);
	
	//imprimo los datos
	for(i=0; i<CSTRUCTS; i++){
		printf("id=%d   msg=%s\n", d[i].id, d[i].msg);
	}
		
	// cierro el archivo
	fclose(fp);
	
	return 0;
}
