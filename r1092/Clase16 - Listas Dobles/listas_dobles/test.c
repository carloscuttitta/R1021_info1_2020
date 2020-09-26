#include <stdio.h>
#include "lista_doble.h"

int main(void){
	nodo_t *lista = NULL;
	nodo_t *nodo = NULL;
	int d, f, sw=0;
	while(1){
		puts("ingrese dato: ");
		scanf("%d", &d);
		printf("ingresado: %d\n", d);
		if(d==0)
			break;
		// creo el nodo
		if((nodo=crear_nodo(d))==NULL)
			return 1;
		// inserto nodo en lista
		if(sw % 2)	// si el switch es impar lo inserto al principio
			lista = agregar_al_principio(lista, nodo);
		else		// si es par lo inserto al final
			lista = agregar_al_final(lista, nodo);
		sw++;
		// imprimir lista
		imprimir_lista(lista, "lista => ");
	}
		
	// ordena la lista en forma descendente
	ordenar_lista(lista, ORDENAR_DESC);
	imprimir_lista(lista, "lista (ord desc) => ");
	
	// ordena la lista en forma ascendente
	ordenar_lista(lista, ORDENAR_ASC);
	imprimir_lista(lista, "lista (ord asc) => ");

	while(1){
		puts("ingrese dato a insertar: ");
		scanf("%d", &d);
		printf("insertar: %d\n", d);
		if(d==0)
			break;
		// creo el nodo
		if((nodo=crear_nodo(d))==NULL)
			return 1;
		// inserto nodo en lista
		lista = insertar(lista, nodo);
		// imprimir lista
		imprimir_lista(lista, "lista => ");
	}

	while(1){
		puts("ingrese dato a quitar: ");
		scanf("%d", &d);
		printf("quitar: %d\n", d);
		if(d==0)
			break;
		// quito un nodo
		if((lista=quitar(lista, d, &f))==NULL){
			if(f == NO_ENCONTRADO)
				printf("%d no encontrado\n", d);
			else
				printf("%d encontrado. La lista quedo vacia\n", d);
		}
		else{
			if(f == NO_ENCONTRADO)
				printf("%d no encontrado\n", d);
		}
		// imprimir lista
		imprimir_lista(lista, "lista => ");
	}
	
	// liberar toda la lista
	liberar_lista(lista);
	puts("chau!\n");
	return 0;
}

