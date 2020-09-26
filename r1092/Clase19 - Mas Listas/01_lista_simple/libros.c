#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -------------------------------------------------
#define OK			0
#define ERRCMDLINE	1
#define ERRFILE		2

#define LISBN		14
#define LTITULO		266

typedef struct {
	char isbn[LISBN];
	char titulo[LTITULO];
} libro_t;

typedef struct Nodo {
	libro_t *libro;
	struct Nodo *prox;
} nodo_t;
	
// -------------------------------------------------
libro_t *lee_libro(FILE *fp);
int insertar_libro(nodo_t **L, libro_t *libro);
void imprime_libros(nodo_t *lista);
void imprime_libro(libro_t *libro);
void salva_libros(FILE *fp, nodo_t *lista);
void salva_libro(FILE *fp, libro_t *libro);
void liberar(nodo_t *l);
// para el ordenamiento
#define ORDENAR_X_ISBN 0 // indica ordenar por isbn
#define ORDENAR_X_TIT  1 // indica ordenar por titulo
#define ORDENAR_ASC    0 // ordenar en forma ascendente
#define ORDENAR_DESC   1 // ordenar en forma descendente
void ordenar_libros(nodo_t *l, int campo, int modo);
int comp_isbn_ascendente(nodo_t a, nodo_t b);
int comp_isbn_descendente(nodo_t a, nodo_t b);
int comp_tit_ascendente(nodo_t a, nodo_t b);
int comp_tit_descendente(nodo_t a, nodo_t b);
// main
int main(int ac, char** av);

// -------------------------------------------------
int main(int ac, char** av){
	FILE *fi;
	libro_t *libro;
	nodo_t *lista=NULL;
	FILE *fo;
	char ofilename[100];
	
	// verifica argumentos de la linea de comandos
	if(ac != 2){
		printf("Error! invocar '%s' <arch.csv>\n", av[0]);
		return ERRCMDLINE;
	}
	
	// abre el archivo .csv
	if((fi = fopen(av[1], "r")) == NULL){
		printf("Error! al abrir '%s'\n", av[1]);
		return ERRFILE;
	}
	
	// arma la lista
	while((libro = lee_libro(fi)) != NULL){
		insertar_libro(&lista, libro);
	}
    fclose(fi);
    
	// imprime la lista segun la armamos
	imprime_libros(lista);
	
	// salva la lista segun la armamos
	strcpy(ofilename, av[1]);
	strcat(ofilename, ".data");
	if((fo = fopen(ofilename, "w")) == NULL){
		printf("Error! al abrir '%s'\n", ofilename);
		return ERRFILE;
	}
	salva_libros(fo, lista);
	fclose(fo);
	
	
	// ordena la lista por isbn ascendente
	printf("------- x isbn ascendente ------------\n");
	ordenar_libros(lista, ORDENAR_X_ISBN, ORDENAR_ASC);
	imprime_libros(lista);
	
	// ordena la lista por isbn descendente
	printf("------- x isbn descendente -----------\n");
	ordenar_libros(lista, ORDENAR_X_ISBN, ORDENAR_DESC);
	imprime_libros(lista);
	
	// ordena la lista por titulo ascendente
	printf("------- x titulo ascendente ----------\n");
	ordenar_libros(lista, ORDENAR_X_TIT, ORDENAR_ASC);
	imprime_libros(lista);
	
	// ordena la lista por titulo descendente
	printf("------- x titulo descendente ---------\n");
	ordenar_libros(lista, ORDENAR_X_TIT, ORDENAR_DESC);
	imprime_libros(lista);

	// libera la memoria
	liberar(lista);

	return OK;
}

// -------------------------------------------------
libro_t *lee_libro(FILE *fp){
	char b[LISBN+LTITULO+3];
	libro_t *l = NULL;

	if(fgets(b, LISBN+LTITULO+2, fp) != NULL){
		l = (libro_t*)malloc(sizeof(libro_t));
		b[strlen(b)-1] = '\0';
		strncpy(l->isbn, b, 13);
		l->isbn[13] = '\0';
		strcpy(l->titulo, &b[14]);
	}	
	return l;
}

// -------------------------------------------------
int insertar_libro(nodo_t **L, libro_t *libro){
	nodo_t *n;
	
	// crea el nodo
	n = (nodo_t*)malloc(sizeof(nodo_t));
	n->libro = libro;
	n->prox = NULL;
	
	// ------------------------------------------
	// insertar en la lista al principio
	n->prox = *L;
    *L = n;
	return OK;
}

//-----------------------------------
void imprime_libros(nodo_t *l){
	if(l==NULL){    // la lista esta vacia
		return;
	}
	do{
		imprime_libro(l->libro);
		l = l->prox;
	}while(l != NULL);
}

// -------------------------------------------------
void salva_libro(FILE *fp, libro_t *l){
    fwrite( (void*)l, sizeof(libro_t), 1, fp);
    fflush(fp);
}

//-----------------------------------
void salva_libros(FILE *fp, nodo_t *l){
	if(l==NULL){    // la lista esta vacia
		return;
	}
	do{
		salva_libro(fp, l->libro);
		l = l->prox;
	}while(l != NULL);
}

// -------------------------------------------------
void imprime_libro(libro_t *l){
	printf("ISBN: %s\t TITULO: %s\n", l->isbn, l->titulo);
}

// -------------------------------------------------
void liberar(nodo_t *l){
	nodo_t * p;
	if(l==NULL) // la lista esta vacia no hay nada para liberar
		return;
	while(1){ 
		if(l->prox == NULL){ // es el ultimo nodo
			free(l->libro);
			free(l);
			return;
		}
		p = l->prox;	// me guardo el proximo
		free(l->libro);	// libero el actual
		free(l);
		l = p;			// me muevo al siguiente
	}
}

//-----------------------------------
void ordenar_libros(nodo_t *lista, int campo, int modo){
	int (*fcomp)(nodo_t, nodo_t);
	nodo_t *pi, *pj;
	libro_t *libro_aux;
	
	// si la lista esta vacia o solo tiene un nodo, no hace nada
	if((lista == NULL) || (lista->prox == NULL))
		return;
	
	// selecciona el modo de ordenar
	if(campo==ORDENAR_X_ISBN && modo==ORDENAR_ASC)
		fcomp = comp_isbn_ascendente;

	if(campo==ORDENAR_X_ISBN && modo==ORDENAR_DESC)
		fcomp = comp_isbn_descendente;

	if(campo==ORDENAR_X_TIT && modo==ORDENAR_ASC)
		fcomp = comp_tit_ascendente;

	if(campo==ORDENAR_X_TIT && modo==ORDENAR_DESC)
		fcomp = comp_tit_descendente;

	for(pi=lista; pi->prox; pi=pi->prox){
		for(pj=pi->prox; pj; pj=pj->prox){
			if(fcomp(*pi, *pj)){
				libro_aux = pi->libro;
				pi->libro = pj->libro;
				pj->libro = libro_aux;
			}
		}
	}
}
			
int comp_isbn_ascendente(nodo_t a, nodo_t b){
	if(strcmp(a.libro->isbn, b.libro->isbn) > 0)
		return 1;
	return 0;
}

int comp_isbn_descendente(nodo_t a, nodo_t b){
	if(strcmp(a.libro->isbn, b.libro->isbn) < 0)
		return 1;
	return 0;
}

int comp_tit_ascendente(nodo_t a, nodo_t b){
	if(strcmp(a.libro->titulo, b.libro->titulo) > 0)
		return 1;
	return 0;
}

int comp_tit_descendente(nodo_t a, nodo_t b){
	if(strcmp(a.libro->titulo, b.libro->titulo) < 0)
		return 1;
	return 0;
}

