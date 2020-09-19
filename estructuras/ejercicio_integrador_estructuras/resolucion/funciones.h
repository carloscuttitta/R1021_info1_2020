#define MAX 1000

typedef struct {
    int id;
    time_t timestamp;
    double valor;
    char unidad[10];
} medicion_t;

int ingresar(medicion_t ** m);
medicion_t* nueva_medicion();
medicion_t* liberar_medicion(medicion_t * m);
void liberar_mediciones(medicion_t ** m);
medicion_t* ingresar_medicion();
int ingreso_terminado(medicion_t * m);

void ordenar_mediciones(medicion_t ** m);
void imprimir_medicion(medicion_t * m);
void imprimir_primeros(medicion_t ** m, int max, char * u);

int contar_mediciones(medicion_t ** m, char * u);
double calcular_maximo(medicion_t ** m, char * u);
double calcular_minimo(medicion_t ** m, char * u);
double calcular_promedio(medicion_t ** m, char * u);

