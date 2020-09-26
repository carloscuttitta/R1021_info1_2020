// implementacion de una LIFO (Last In First Out)
// tambien llamada STACK o PILA

#include <stdio.h>
#include <stdlib.h>

struct nodo {
	int dato;
	struct nodo *prox;
};
typedef struct nodo nodo_t;

//-----------------------------------
nodo_t* crear_nodo(int data);
nodo_t* push_lifo(nodo_t *l,  int d);
nodo_t* pop_lifo(nodo_t *l, int *d);
void    imprimir_lista(nodo_t *l, const char *s);
void    liberar_lista(nodo_t *l);

//-----------------------------------
int main(void){
	nodo_t *lifo = NULL;
	int d=1;
	
    puts("... voy haciendo push(es)");
    while(d !=0 ){
        puts("ingrese dato: ");
        scanf("%d", &d);
        lifo = push_lifo(lifo, d);
        imprimir_lista(lifo, "lifo => ");
    }
	
	puts("... voy haciendo pop(es)");
	while((lifo = pop_lifo(lifo, &d))){	
        printf("dato = %d\n", d);
        imprimir_lista(lifo, "fifo => ");
	}

	liberar_lista(lifo);
	return 0;
}

//-----------------------------------
nodo_t *crear_nodo(int data){
	nodo_t *p;
	p = (nodo_t *)malloc(sizeof(nodo_t));
	if(p==NULL){
		puts("No pude crear el nodo\n");
		return p;
	}
	p->dato = data;
	p->prox = NULL;
	return p;
}
	
//-----------------------------------
nodo_t* push_lifo(nodo_t *l, int d){
	nodo_t *n;
	
	if((n = crear_nodo(d)) == NULL) // error al crear el nodo
		return NULL;

	if(l==NULL) //la lista esta vacia
		return n;   		

	//no esta vacia. inserto nodo al principio
	n->prox = l;
	return n;
}

//-----------------------------------
nodo_t* pop_lifo(nodo_t *l, int *d){
	nodo_t *p;
	if(l==NULL){ // la lista esta vacia
		puts("la lifo esta vacia");
		return l;
	}
	*d = l->dato;
	p = l->prox;
	free(l);
	return p;
}


//-----------------------------------
void imprimir_lista(nodo_t *l, const char *s){
	if(l==NULL){ 
		puts("la lista esta vacia");
		return;
	}
	printf("%s", s); 
	do{
		printf("%d ", l->dato);
		l = l->prox;
	}while(l != NULL);
	printf("\n");
}

//-----------------------------------
void liberar_lista(nodo_t *l){
	nodo_t * p;
	if(l==NULL){ // la lista esta vacia no hay nada para liberar
		puts("lista vacia. nada para liberar");
		return;
	}
	while(1){ 
		if(l->prox == NULL){ // es el ultimo nodo
			free(l);
			return;
		}
		p = l->prox;	// me guardo el proximo
		free(l);		// libero el actual
		l = p;			// me muevo al siguiente
	}
}	
	
	









