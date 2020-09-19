#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "funciones.h"

int ingresar(medicion_t ** m) {
    medicion_t ** i = m;
    
    do {
        *m = ingresar_medicion();
        m++;
    } while(*(m-1));
    
    return m-i-1;
}

medicion_t* nueva_medicion() {
    return (medicion_t*) malloc(sizeof(medicion_t));
}

medicion_t* ingresar_medicion() {
    medicion_t * m;
    m = nueva_medicion();
    scanf("%d %d %lf %s", &m->id, (int *) &m->timestamp, &m->valor, m->unidad);

    if(ingreso_terminado(m))
        m = liberar_medicion(m);
    
    return m;
}

medicion_t* liberar_medicion(medicion_t * m) {
    free(m);
    return NULL;
}

int ingreso_terminado(medicion_t * m) {
    return !(m->id || m->timestamp || m->valor);
}

void imprimir_medicion(medicion_t * m) {
    printf("%d\t%d\t%.9f\t%s\n", m->id, (int)m->timestamp, m->valor, m->unidad);
}

int contar_mediciones(medicion_t ** m, char * u) {
    int c = 0;
    for(;*m;m++) {
        if(!strcmp(u,(*m)->unidad )) {
            c++;
        }
    }
    return c;
}

double calcular_maximo(medicion_t ** m, char * u) {
    double r = -1.0;
    for(;*m;m++) {
        if(!strcmp(u,(*m)->unidad ) && (*m)->valor > r) {
            r = (*m)->valor;
        }
    }
    return r;
}

double calcular_minimo(medicion_t ** m, char * u) {
    double r = 999999999999999999;
    for(;*m;m++) {
        if(!strcmp(u,(*m)->unidad ) && (*m)->valor < r) {
            r = (*m)->valor;
        }
    }
    return r;
}

double calcular_promedio(medicion_t ** m, char * u) {
    double p = 0.0;
    int c = 0;
    for(;*m;m++) {
        if(!strcmp(u,(*m)->unidad)) {
            p += (*m)->valor;
            c++;
        }
    }
    return p/c;
}

void ordenar_mediciones(medicion_t ** m) {
    int i, j;
    medicion_t * aux;
    for(i=0; *(m+i+2) ;i++) {
        for(j=i+1; *(m+j+1) ;j++) {
            if( m[i]->timestamp < m[j]->timestamp ) {
                aux = m[i];
                *(m+i) = *(m+j);
                m[j] = aux;
            
            }
        }
    }
}

void imprimir_primeros(medicion_t ** m, int max, char * u) {
    int i = 0;
    for(;*m && i<max;m++) {
        if(!strcmp(u,(*m)->unidad)) {
            imprimir_medicion(*m);
            i++;
        }
    }
}

void liberar_mediciones(medicion_t ** m) {
    for(;*m;m++) {
        liberar_medicion(*m);
    }
}
