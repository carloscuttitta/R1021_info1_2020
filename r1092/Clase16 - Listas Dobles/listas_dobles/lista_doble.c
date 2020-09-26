#include <stdio.h>
#include <stdlib.h>
#include "lista_doble.h"

int comp_n_ascendente(nodo_t a, nodo_t b);
int comp_n_descendente(nodo_t a, nodo_t b);

//================================================================
// crea un nodo y lo inicializa con el dato en 'n'
nodo_t *crear_nodo(int n){
	struct data *d;
	nodo_t *nodo;
	
	if((d = (struct data *)malloc(sizeof(struct data))) == NULL)
		return NULL;
		
	if((nodo = (nodo_t *)malloc(sizeof(nodo_t))) == NULL)
		return NULL;

	d->n = n;
	nodo->dato = d;
	nodo->prev = NULL;
	nodo->prox = NULL;
	return nodo;
}

//================================================================
// agrega un nodo al principio de la lista 
nodo_t *agregar_al_principio(nodo_t *lista, nodo_t *nodo){
	if(lista == NULL)	// la lista esta vacia
		return nodo;
	lista->prev = nodo;
	nodo->prox = lista;
	return nodo;
}

//================================================================
// agrega un nodo al final de la lista 
nodo_t *agregar_al_final(nodo_t *lista, nodo_t *nodo){ 
 	nodo_t *lista_original = lista;
	if(lista==NULL) //la lista esta vacia
		return nodo;   		
	//no esta vacia. voy hasta el final y agrego nodo
	while(lista->prox != NULL)
		lista = lista->prox;
	lista->prox = nodo;
	nodo->prev = lista;
	return lista_original;
}

//================================================================
// inserta un nodo en una lista ordenada 
nodo_t *insertar(nodo_t *lista, nodo_t *nodo){
	nodo_t *lista_original = lista;
	if(lista==NULL) // la lista esta vacia
		return nodo;   		

	if(nodo->dato->n < lista->dato->n){	// lo inserto al principio
		lista->prev = nodo;
		nodo->prox = lista;
		return nodo;
	}

	// busco donde insertar
	while(lista->prox != NULL){
		if((nodo->dato->n > lista->dato->n) && (nodo->dato->n <= lista->prox->dato->n)){
			nodo->prox = lista->prox;
			lista->prox->prev = nodo;
			lista->prox = nodo;
			nodo->prev = lista;
			return lista_original;
		}
		lista = lista->prox;
	}
	// llego al final
	lista->prox = nodo;
	nodo->prev = lista;
	return lista_original;
} 

//================================================================
// busca un nodo con valor 'n' en la lista
nodo_t *buscar(nodo_t *lista, int n){
	if(lista==NULL) // la lista esta vacia
		return NULL;
	do{
		if(lista->dato->n == n)
			return lista;
		lista = lista->prox;
	}while(lista!=NULL);
	return NULL;
}

//================================================================
// saca un nodo del principio de la lista 
nodo_t *sacar_del_principio(nodo_t *lista, nodo_t **p){
	*p = lista;
	if(lista){ // la lista NO esta vacia
		if(lista->prox) // hay mas de un nodo
			lista->prox->prev = NULL;
		lista = lista->prox; 
		(*p)->prox = NULL;
	}
	return lista;
} 

//================================================================
// saca un nodo del final de la lista 
nodo_t *sacar_del_final(nodo_t *lista, nodo_t **p){
	nodo_t *lista_original = lista;
	*p = NULL;
	if(lista==NULL){ // la lista esta vacia
		return NULL;
	}
	if(lista->prox == NULL){ // hay un solo nodo
		*p = lista;
		return NULL;
	}
	while(lista->prox->prox != NULL) // me muevo hasta el ante-ultimo
		lista = lista->prox;   		
	lista->prox->prev = NULL;
	*p = lista->prox;
	lista->prox = NULL;
	return lista_original;
} 

//================================================================
// quita un nodo con valor 'n' en la lista
nodo_t *quitar(nodo_t *lista, int n, int *flag){
	nodo_t *nodo, *p;
	if((nodo = buscar(lista, n)) == NULL){
		*flag = NO_ENCONTRADO;
		return lista;
	}
	
	// si es el unico, libera nodo y retorna la lista vacia
	if((nodo->prev == NULL) && (nodo->prox == NULL)){
		liberar_nodo(nodo);
		*flag = ENCONTRADO;
		return NULL;
	}
	
	*flag = ENCONTRADO;
	// hay mas de un nodo
	if(nodo->prev != NULL){		// no es el primero
		nodo->prev->prox = nodo->prox;
		if(nodo->prox != NULL){	// no es el ultimo
			nodo->prox->prev = nodo->prev;
			nodo->prev = NULL;
		}
		else{					// es el ultimo
			nodo->prev->prox = NULL;
		}
		liberar_nodo(nodo);
		return lista;
	}
	else{						// es el primero
		nodo->prox->prev = NULL;
		p = nodo->prox;
		liberar_nodo(nodo);
		return p;
	}
} 

//================================================================
// ordena la lista segun el 'modo' (ascendente o descendente)
void ordenar_lista(nodo_t *lista, int modo){
	int (*fcomp)(nodo_t, nodo_t);
	nodo_t *pi, *pj;
	struct data *saux;

	// si la lista esta vacia o solo tiene un nodo, no hace nada
	if((lista == NULL) || (lista->prox == NULL))
		return;
	
	// selecciona el modo de ordenar
	if(modo==ORDENAR_ASC)
		fcomp = comp_n_ascendente;
	else
		fcomp = comp_n_descendente;

	for(pi=lista; pi->prox; pi=pi->prox){
		for(pj=pi->prox; pj; pj=pj->prox){
			if(fcomp(*pi, *pj)){
				saux = pi->dato;
				pi->dato = pj->dato;
				pj->dato = saux;
			}
		}
	}
}
			
int comp_n_ascendente(nodo_t a, nodo_t b){
	if(a.dato->n > b.dato->n)
		return 1;
	return 0;
}

int comp_n_descendente(nodo_t a, nodo_t b){
	if(a.dato->n < b.dato->n)
		return 1;
	return 0;
}

//================================================================
// libera un nodo 
void liberar_nodo(nodo_t *nodo){
	free(nodo->dato);
	free(nodo);
} 

//================================================================
void liberar_lista(nodo_t *lista){
	nodo_t *p;
	imprimir_lista(lista, "lista => ");
	do {
		lista=sacar_del_principio(lista, &p);
		if(p){
			printf("liberando => %d\n", p->dato->n);
			liberar_nodo(p);
		}
	}while(lista != NULL);
}	

//================================================================
// imprime una lista
void imprimir_lista(nodo_t *lista, const char *s){
	if(lista==NULL){ 
		puts("la lista esta vacia");
		return;
	}
	printf("%s", s); 
	do{
		printf("%d ", lista->dato->n);
		lista = lista->prox;
	}while(lista != NULL);
	printf("\n");
}
 
