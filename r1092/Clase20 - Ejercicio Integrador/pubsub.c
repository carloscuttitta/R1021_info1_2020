#include "pubsub.h"
#include <string.h>
#include <malloc.h>

int existe(sub_t *s, char *id) {
	while(s) {
		if(!strcmp(s->id, id)) {
			return TRUE;
		}
		s = s->sig;
	}
	return FALSE;
}

int subscripto(unsigned int * canales, int c) {
  while(*canales) {
    if(c==*canales)
      return TRUE;
    canales++;
  }
  return FALSE;
}

int suscribir(sub_t **s, char *id, unsigned int *canales, int (*e)(char *)) {
  sub_t *n = NULL;

  if(existe(*s, id))
    return ERR_ITEM;

  n = (sub_t *) malloc(sizeof(sub_t));

  if(!n)
    return ERR_MEMORY;

  strcpy(n->id,id);
  n->canales = canales;
  n->enviar = e;

  if(*s) {
    // Cosiendo la lista si ya habia algo
    n->sig = *s;
  }
  *s = n;

  return OK;
}

int desuscribir(sub_t **s, char *id) {
  sub_t *i, *p=NULL;
  i = *s;

  // Primer elemento
  if(!strcmp(i->id, id)) {
    *s = i->sig;
    free(i);
    return OK;
  }

  // Siguientes y final
  do {
    p = i;
    i = i->sig;
    if(i && !strcmp(i->id, id)) {
      p->sig = i->sig;
      free(i);
      return OK;
    }       
  } while(i);

  // No se encontro el elemento
  return ERR_ITEM;
}

int publicar(sub_t *s, char *msg, unsigned int canal) {
  // Implementar
  while(s) {
    if(subscripto(s->canales,canal))
      s->enviar(msg);
    s = s->sig;
  }
  return 0;
}