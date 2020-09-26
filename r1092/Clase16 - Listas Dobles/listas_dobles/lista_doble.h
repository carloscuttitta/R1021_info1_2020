/* lista_doble.h */

// para la funcion ordenar
#define ORDENAR_ASC    0 // ordenar en forma ascendente
#define ORDENAR_DESC   1 // ordenar en forma descendente

// para la funcion quitar
#define NO_ENCONTRADO 0	// si el nodo a quitar no esta en la lista
#define ENCONTRADO    1 // si el nodo estaba en la lista


struct data{
	int n;
	};
	
struct nodo{
	struct data *dato;	// puntero a los datos 
	struct nodo *prox;	// puntero al proximo nodo
	struct nodo *prev;	// puntero al nodo previo
	};
typedef struct nodo nodo_t;

// crea un nodo y lo inicializa con el dato en 'n'
nodo_t *crear_nodo(int n);

// agrega un nodo al principio de la lista 
nodo_t *agregar_al_principio(nodo_t *lista, nodo_t *nodo); 

// agrega un nodo al final de la lista 
nodo_t *agregar_al_final(nodo_t *lista, nodo_t *nodo); 

// inserta un nodo en una lista ordenada 
nodo_t *insertar(nodo_t *lista, nodo_t *nodo); 

// busca un nodo con valor 'n' en la lista
nodo_t *buscar(nodo_t *lista, int n);

// saca un nodo del principio de la lista 
nodo_t *sacar_del_principio(nodo_t *lista, nodo_t **p); 

// saca un nodo del final de la lista 
nodo_t *sacar_del_final(nodo_t *lista, nodo_t **p); 

// quita un nodo con valor 'n' en la lista
nodo_t *quitar(nodo_t *lista, int n, int *flag); 

// libera un nodo 
void liberar_nodo(nodo_t *nodo); 

// libera toda la lista
void liberar_lista(nodo_t *lista);

// imprime una lista
void imprimir_lista(nodo_t *lista, const char *s);

// ordena la lista segun el 'modo' (ascendente o descendente)
void ordenar_lista(nodo_t *lista, int modo);


