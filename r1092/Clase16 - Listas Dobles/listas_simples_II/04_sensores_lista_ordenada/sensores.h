/* sensores.h */
#define TMIN	10	// temperatura minima
#define TMAX	65	// temperatura maxima
#define PERIODO	5	// cada cuanto se leen los sensores (en segundos)

// para la funcion ordenar_sensores
#define ORDENAR_X_ID   0 // indica ordenar por id
#define ORDENAR_X_TEMP 1 // indica ordenar por temperatura
#define ORDENAR_ASC    0 // ordenar en forma ascendente
#define ORDENAR_DESC   1 // ordenar en forma descendente

struct dato_sensor{
		char	id[20];			// identificacion del sensor
		double	temp;			// temperatura medida
	};
	
struct nodo_sensor{
	struct dato_sensor *dato;	// puntero a los datos de un sensor
	struct nodo_sensor *prox;	// puntero al proximo sensor
	};
typedef struct nodo_sensor sensor_t;

// verifica si se pasaron por lo menos un id de sensor y no mas de la cant max
// imprime el mensaje "cantidad de argumentos incorrecta" si hubiere un error
// devuelve 0 si todo esta bien o 1 si hubo error
int  verifica_argumentos(int c, char **a);

// inicializa los sensores, cada uno con un id y con temperatura igual a la minima
// el siguiente al ultimo se inicializa con id nulo.
sensor_t* inicializa_sensores(sensor_t *s, int c, char **a);

// agrega un sensor a la lista
sensor_t* agregar_sensor(sensor_t *l, sensor_t *n);

// inicializa un sensor con un id y una temperatura
sensor_t* inicializa_sensor(sensor_t *s, char *id, double t);

// lee todos los sensores
void lee_sensores(sensor_t *s);

// lee un sensor
void lee_sensor(sensor_t *s);

// imprime todos los sensores
void imprime_sensores(sensor_t *s);

// imprime un sensor
void imprime_sensor(sensor_t *s);

// calcula la maxima temperatura
sensor_t *calcula_maxt(sensor_t *s);

// imprime el sensor con temperatura maxima
void imprime_maxt(sensor_t *s);

// calcula la minima temperatura
sensor_t *calcula_mint(sensor_t *s);

// imprime el sensor con minima temperatura
void imprime_mint(sensor_t *s);

// calcula la temperatura promedio
double calcula_promedio(sensor_t *s);

// imprime la temperatura promedio
void imprime_promedio(double prom);

// busca un sensor por su id
// devuelve el puntero al sensor o NULL si no lo encuentra
sensor_t *buscar_sensor(sensor_t *s, char *id);

// ordena el array de sensores
// se le pasa el puntero al comienzo del array y
// dos enteros, el primero indica por cual campo ordenar (id o temp)
// el segundo si es en forma ascendente o descendente
void ordenar_sensores(sensor_t *s, int campo, int modo);


