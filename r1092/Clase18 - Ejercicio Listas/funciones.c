#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "funciones.h"

nodo_t * ingresar(nodo_t * n) {
  nodo_t * aux;
  FILE *fp;
  fp = fopen("mediciones.data","r");
  while((aux = ingresar_medicion(fp))) {
    if(n==NULL) {
      n = aux;
    }
    else {
      aux->next = n;
      n = aux;
    } 
  }
  fclose(fp);
  return n;
}

nodo_t * nueva_medicion() {
    nodo_t * n;
    n = (nodo_t *) malloc(sizeof(nodo_t));
    n->med = (medicion_t*) malloc(sizeof(medicion_t));
    n->next = NULL;
    return n;
}

nodo_t * ingresar_medicion(FILE * fp) {
    nodo_t * n;

    if(feof(fp)) return NULL;

    n = nueva_medicion();
    fscanf(fp, "%d %d %lf %s", &n->med->id, (int *) &n->med->timestamp, &n->med->valor, n->med->unidad);
    
    return n;
}

nodo_t* liberar_medicion(nodo_t * n) {
    free(n->med);
    free(n);
    return NULL;
}

void imprimir_medicion(medicion_t * m) {
    printf("%d\t%d\t%.9f\t%s\n", m->id, (int)m->timestamp, m->valor, m->unidad);
}

int contar_mediciones(nodo_t * n, char * u) {
    int c = 0;
    while(n) {
        if(!strcmp(u,n->med->unidad)) {
            c++;
        }
        n = n->next;
    }
    return c;
}

double calcular_maximo(nodo_t * n, char * u) {
    double r = -1.0;
    while(n) {
        if(!strcmp(u,n->med->unidad) && n->med->valor > r) {
            r = n->med->valor;
        }
        n = n->next;
    }
    return r;
}

double calcular_minimo(nodo_t * n, char * u) {
    double r = 999999999999999999;
    while(n) {
        if(!strcmp(u,n->med->unidad ) && n->med->valor < r) {
            r = n->med->valor;
        }
        n = n->next;
    }
    return r;
}

double calcular_promedio(nodo_t * n, char * u) {
    double p = 0.0;
    int c = 0;
    for(   ;  n ; n=n->next ) {
        if(!strcmp(u,n->med->unidad)) {
            p += n->med->valor;
            c++;
        }
    }
    return p/c;
}

void imprimir_primeros(nodo_t * n, int max, char * u) {
    int i = 0;
    while(n) {
        if(!strcmp(u,n->med->unidad)) {
            imprimir_medicion(n->med);
            i++;
        }
        if(i>=10) 
	  break;
	n = n->next;
    }
}

void liberar_mediciones(nodo_t * n) {
  nodo_t * aux;
  while(n) {
    aux = n->next;
    liberar_medicion(n);
    n = aux;
  }
}
