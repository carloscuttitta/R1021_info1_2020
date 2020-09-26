/* sensores.c */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "sensores.h"

//-----------------------------------
int verifica_argumentos(int c, char **a){
	if(c<2){
		printf("cantidad de argumentos incorrecta\n");
		return 1;
	}
	return 0;
}

//-----------------------------------
sensor_t* inicializa_sensores(sensor_t *s, int c, char **a){
	sensor_t *p;
	struct dato_sensor *d;
	int i;
	for(i=1; i<c; i++){
		p = (sensor_t*)malloc(sizeof(sensor_t));
		d = (struct dato_sensor*)(malloc(sizeof(struct dato_sensor)));
		p->dato = d;
		p = inicializa_sensor(p, a[i], (double)TMIN);
		s = agregar_sensor(s, p);
	}
	srand((int)getpid());
	return s;
}

//-----------------------------------
sensor_t* inicializa_sensor(sensor_t *s, char *id, double t){
    strcpy(s->dato->id, id);
    s->dato->temp = t;
    s->prox = NULL;
    return s;
}

//-----------------------------------
sensor_t* agregar_sensor(sensor_t *l, sensor_t *n){
	sensor_t *lista_original = l;
	if(l==NULL) //la lista esta vacia
		return n;

	//no esta vacia. voy hasta el final y agrego nodo
	while(l->prox != NULL)
		l = l->prox;
	l->prox = n;
	return lista_original;
}

//-----------------------------------
void lee_sensores(sensor_t *s){
	do{
		lee_sensor(s);
		s = s->prox;
	}while(s!=NULL);
}

//-----------------------------------
void lee_sensor(sensor_t *s){
	s->dato->temp = (rand()%((TMAX-TMIN)*10) + TMIN*10)/10.0;
}

//-----------------------------------
void imprime_sensores(sensor_t *s){
	do{
		imprime_sensor(s);
		s = s->prox;
	}while(s!=NULL);
}

//-----------------------------------
void imprime_sensor(sensor_t *s){
	printf("%s = %.1f\n", s->dato->id, s->dato->temp);
}

//-----------------------------------
sensor_t *calcula_maxt(sensor_t *s){
	double max = (double)TMIN;
	sensor_t *p= s;

	do{
		if(s->dato->temp > max){
			max = s->dato->temp;
			p = s;
		}
		s = s->prox;
	}while(s!=NULL);
	return p;	
}

//-----------------------------------
void imprime_maxt(sensor_t *s){
	printf("MAX: %s = %.1f\n", s->dato->id, s->dato->temp);
}

//-----------------------------------
sensor_t *calcula_mint(sensor_t *s){
	double min = (double)TMAX;
	sensor_t *p= s;
	
	do{
		if(s->dato->temp < min){
			min = s->dato->temp;
			p = s;
		}
		s = s->prox;
	}while(s!=NULL);
	return p;
}

//-----------------------------------
void imprime_mint(sensor_t *s){
	printf("MIN: %s = %.1f\n", s->dato->id, s->dato->temp);
}

//-----------------------------------
double calcula_promedio(sensor_t *s){
	int n = 0;
	double suma = 0.0;
	do{
		suma += s->dato->temp;
		s = s->prox;
		n++;
	}while(s!=NULL);
	return suma/(double)n;
}

//-----------------------------------
void imprime_promedio(double prom){
	printf("PROMEDIO: %.1f\n", prom);
}

//-----------------------------------
sensor_t *buscar_sensor(sensor_t *s, char *id){
	do{
		if(strcmp(s->dato->id, id)==0)
			return s;
		s = s->prox;
	}while(s!=NULL);
	return NULL;
}


