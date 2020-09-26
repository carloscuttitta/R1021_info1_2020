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
	struct Nodo *p_isbn;
	struct Nodo *p_titulo;
} nodo_t;
	
// -------------------------------------------------
libro_t *lee_libro(FILE *fp);
void imprime_libro(libro_t *libro);
int insertar_libro(nodo_t **Li, nodo_t **Lt, libro_t *libro);
void imprime_x_isbn(nodo_t *l);
void imprime_x_titulo(nodo_t *l);
void liberar(nodo_t *l);
int main(int ac, char** av);

// -------------------------------------------------
int main(int ac, char** av){
	FILE *f;
	libro_t *libro;
	nodo_t *l_isbn=NULL;
	nodo_t *l_titulo=NULL;
	
	// verifica argumentos de la linea de comandos
	if(ac != 2){
		printf("Error! invocar '%s' <arch.csv>\n", av[0]);
		return ERRCMDLINE;
	}
	
	// abre el archivo .csv
	if((f = fopen(av[1], "r")) == NULL){
		printf("Error! al abrir '%s'\n", av[1]);
		return ERRFILE;
	}
	
	// arma la lista
	while((libro = lee_libro(f)) != NULL){
		insertar_libro(&l_isbn, &l_titulo, libro);
	}
	fclose(f);

	// la imprime ordenada por isbn
	imprime_x_isbn(l_isbn);
	
	// separador
	printf("-----------------------------------------------\n");
	
	// la imprime ordenada por titulo
	imprime_x_titulo(l_titulo);

	// libera la memoria
	liberar(l_isbn);

	return OK;
}

// -------------------------------------------------
libro_t *lee_libro(FILE *fp){
	libro_t *l = NULL;

	l = (libro_t*)malloc(sizeof(libro_t));
	if(fscanf(fp, "%13c;%[a-zA-Z0-9(), -]\n", l->isbn, l->titulo) != 2){
	    free(l);
	    return NULL;
	}
    l->isbn[13] = '\0';
	return l;
}

// -------------------------------------------------
void imprime_libro(libro_t *l){
	printf("ISBN: %s\t TITULO: %s\n", l->isbn, l->titulo);
}

// -------------------------------------------------
int insertar_libro(nodo_t **Li, nodo_t **Lt, libro_t *libro){
	nodo_t *n, *paux;
	
	// crea el nodo
	n = (nodo_t*)malloc(sizeof(nodo_t));
	n->libro = libro;
	n->p_isbn = NULL;
	n->p_titulo = NULL;
	
	// ------------------------------------------
	// insertar en la lista: primero para el ISBN
	if((*Li) == NULL){ 
		// la lista esta vacia
		*Li = n;
	}
	else{
		if(strcmp(n->libro->isbn, (*Li)->libro->isbn) < 0){
			// inserta al principio
			n->p_isbn = *Li;
			*Li = n;
		}
		else{
			paux = *Li;
			while(1){
				if(paux->p_isbn == NULL){
					// llego al final. inserta al final
					paux->p_isbn = n;
					break;
				}
				if(strcmp(n->libro->isbn, paux->p_isbn->libro->isbn) < 0){
					// insertar aca
					n->p_isbn = paux->p_isbn;
					paux->p_isbn = n;
					break;
				}
				paux = paux->p_isbn;
			}
		}
	}
	
	// ------------------------------------------
	// insertar en la lista: ahora para el TITULO
	if((*Lt) == NULL){ 
		// la lista esta vacia
		*Lt = n;
	}
	else{
		if(strcmp(n->libro->titulo, (*Lt)->libro->titulo) < 0){
			// inserta al principio
			n->p_titulo = *Lt;
			*Lt = n;
		}
		else{
			paux = *Lt;
			while(1){
				if(paux->p_titulo == NULL){
					// llego al final. inserta al final
					paux->p_titulo = n;
					break;
				}
				if(strcmp(n->libro->titulo, paux->p_titulo->libro->titulo) < 0){
					// insertar aca
					n->p_titulo = paux->p_titulo;
					paux->p_titulo = n;
					break;
				}
				paux = paux->p_titulo;
			}
		}
	}
	return OK;
}

// -------------------------------------------------
void imprime_x_isbn(nodo_t *l){
	while(l){
		printf("x_ISBN -> ");
		imprime_libro(l->libro);
		l = l->p_isbn;
	}
}

// -------------------------------------------------
void imprime_x_titulo(nodo_t *l){
	while(l){
		printf("x_TITULO -> ");
		imprime_libro(l->libro);
		l = l->p_titulo;
	}
}

// libera memoria de los nodos forma recursiva.
void liberar(nodo_t * l) {
	if(l==NULL) {
		return;
	}
	liberar(l->p_isbn);
	free(l->libro);
	free(l);
	return;
}
