/* sensores.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "sensores.h"

//---------------------------------------------------------------------------
int comp_id_ascendente(sensor_t a, sensor_t b);
int comp_id_descendente(sensor_t a, sensor_t b);
int comp_temp_ascendente(sensor_t a, sensor_t b);
int comp_temp_descendente(sensor_t a, sensor_t b);

//---------------------------------------------------------------------------
int verifica_argumentos(int c, char **a){
	if(c<2 || c>CSENS+1){
		printf("cantidad de argumentos incorrecta\n");
		return 1;
	}
	return 0;
}
//---------------------------------------------------------------------------
void inicializa_sensores(sensor_t *s, int c, char **a){
	int i;
	for(i=1; i<c; i++, s++)
		inicializa_sensor(s, a[i], (double)TMIN);
	strcpy(s->id, "");
	srand((int)getpid());
	
}
//---------------------------------------------------------------------------
void inicializa_sensor(sensor_t *s, char *id, double t){
	strcpy(s->id, id);
	s->temp = t;
}
//---------------------------------------------------------------------------
void lee_sensores(sensor_t *s){
	do{
		lee_sensor(s);
		s++;
	}while(strcmp(s->id, "")!=0);
}
//---------------------------------------------------------------------------
void lee_sensor(sensor_t *s){
	s->temp = (rand()%((TMAX-TMIN)*10) + TMIN*10)/10.0;
}
//---------------------------------------------------------------------------
void imprime_sensores(sensor_t *s){
	do{
		imprime_sensor(s);
		s++;
	}while(strcmp(s->id, "")!=0);
}
//---------------------------------------------------------------------------
void imprime_sensor(sensor_t *s){
	printf("%s = %.1f\n", s->id, s->temp);
}
//---------------------------------------------------------------------------
sensor_t *calcula_maxt(sensor_t *s){
	double max = (double)TMIN;
	sensor_t *p= s;
	
	while(1){
		if(strcmp(s->id, "")==0)
			return p;
		if(s->temp > max){
			max = s->temp;
			p = s;
		}
		s++;
	}
}
//---------------------------------------------------------------------------
void imprime_maxt(sensor_t *s){
	printf("MAX: %s = %.1f\n", s->id, s->temp);
}
//---------------------------------------------------------------------------
sensor_t *calcula_mint(sensor_t *s){
	double min = (double)TMAX;
	sensor_t *p= s;
	
	while(1){
		if(strcmp(s->id, "")==0)
			return p;
		if(s->temp < min){
			min = s->temp;
			p = s;
		}
		s++;
	}
}
//---------------------------------------------------------------------------
void imprime_mint(sensor_t *s){
	printf("MIN: %s = %.1f\n", s->id, s->temp);
}
//---------------------------------------------------------------------------
double calcula_promedio(sensor_t *s){
	int n = 0;
	double suma = 0.0;
	do{
		suma += s->temp;
		s++;
		n++;
	}while(strcmp(s->id, "")!=0);
	return suma/(double)n;
}
//---------------------------------------------------------------------------
void imprime_promedio(double prom){
	printf("PROMEDIO: %.1f\n", prom);
}
//---------------------------------------------------------------------------
sensor_t *buscar_sensor(sensor_t *s, char *id){
	do{
		if(strcmp(s->id, id)==0)
			return s;
		s++;
	}while(strcmp(s->id, "")!=0);
	return NULL;
}
//---------------------------------------------------------------------------
void ordenar_sensores(sensor_t *s, int campo, int modo){
	int nsensores;
	int (*fcomp)(sensor_t, sensor_t);
	int i, j;
	sensor_t saux;
	
	if(campo==ORDENAR_X_ID && modo==ORDENAR_ASC)
		fcomp = comp_id_ascendente;

	if(campo==ORDENAR_X_ID && modo==ORDENAR_DESC)
		fcomp = comp_id_descendente;

	if(campo==ORDENAR_X_TEMP && modo==ORDENAR_ASC)
		fcomp = comp_temp_ascendente;

	if(campo==ORDENAR_X_TEMP && modo==ORDENAR_DESC)
		fcomp = comp_temp_descendente;
		
	for(nsensores=0; strcmp(s[nsensores].id, ""); nsensores++);

	for(i=0; i<nsensores-1; i++){
		for(j=i+1; j<nsensores; j++){
			if(fcomp(s[i], s[j])){
				saux = s[i];
				s[i] = s[j];
				s[j] = saux;
			}
		}
	}
}
//---------------------------------------------------------------------------
int comp_id_ascendente(sensor_t a, sensor_t b){
	if(strcmp(a.id, b.id) > 0)
		return 1;
	return 0;
}
//---------------------------------------------------------------------------
int comp_id_descendente(sensor_t a, sensor_t b){
	if(strcmp(a.id, b.id) < 0)
		return 1;
	return 0;
}
//---------------------------------------------------------------------------
int comp_temp_ascendente(sensor_t a, sensor_t b){
	if(a.temp > b.temp)
		return 1;
	return 0;
}
//---------------------------------------------------------------------------
int comp_temp_descendente(sensor_t a, sensor_t b){
	if(a.temp < b.temp)
		return 1;
	return 0;
}







