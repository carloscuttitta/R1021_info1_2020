#define OK 0
#define TRUE 1
#define FALSE 0
#define ERR_MEMORY -1
#define ERR_ITEM -2

typedef struct sub_s {
  // Identificador único del subscriptor
  char id[100];
  // Lista de canales a los que está subscripto.
  unsigned int *canales;
  // Puntero a función para enviar mensajes
  int (*enviar)(char *);
  // Puntero al siguiente nodo
  struct sub_s *sig;
} sub_t;

int suscribir(sub_t **s, char *id, unsigned int *canales, int (*e)(char *));
int desuscribir(sub_t **s, char *id);
int publicar(sub_t *s, char *msg, unsigned int canal);

// Funciones auxiliares (NUNCA VIENEN EN EL EXAMEN)
int existe(sub_t *s, char *id);
int subscripto(unsigned int * canales, int c);