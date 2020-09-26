typedef struct {
    int id;
    time_t timestamp;
    double valor;
    char unidad[10];
} medicion_t;

struct nodo {
  medicion_t * med;
  struct nodo * prev;
  struct nodo * next;
};
typedef struct nodo nodo_t;

nodo_t * ingresar(nodo_t * n);
nodo_t * nueva_medicion();
nodo_t * liberar_medicion(nodo_t * n);
void liberar_mediciones(nodo_t * n);
nodo_t * ingresar_medicion();
int ingreso_terminado(nodo_t * n);

void ordenar_mediciones(nodo_t * n);
void imprimir_medicion(medicion_t * n);
void imprimir_primeros(nodo_t * n, int max, char * u);

int contar_mediciones(nodo_t * n, char * u);
double calcular_maximo(nodo_t * n, char * u);
double calcular_minimo(nodo_t * n, char * u);
double calcular_promedio(nodo_t * n, char * u);

// Busca la primer medicion para la unidad dada
nodo_t * buscar_primera(nodo_t * n, char * s);
// Cuenta cuantos nodos tenemos en la lista delante de un nodo dado
int contar_al_inicio(nodo_t * n);
// Cuenta cuantos nodos tenemos en la lista detras de un nodo dado
int contar_al_final(nodo_t * n);