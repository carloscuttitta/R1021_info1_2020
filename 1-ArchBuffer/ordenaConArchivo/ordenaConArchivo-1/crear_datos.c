#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

enum{TENSION, CORRIENTE, RESISTENCIA, CAPACIDAD, FRECUENCIA, PRESION, FUERZA, VELOCIDAD, ACELERACION, LUZ};

#define MEDICIONES 50
#define DELTAT 10000

typedef struct{
    int id;
    time_t timestamp;
    char output[20];
    float valor;
    char unidad[10];
} sensor_t;

int main(int ac, char **av){
    
    FILE *fp;
    int i=0;
    sensor_t aux;

    struct tm *tlocal; 
    
    
	// verifico argumentos de la linea de comandos
	if(ac != 2){
		printf("ERROR! Invocar %s <archivo_donde_salvar>\n", av[0]);
		return 1;
	}
	
	// abro el archivo
	if((fp = fopen(av[1], "w")) == NULL){
		printf("ERROR! No pude abrir %s", av[1]);
		return 2;
	}

    srand(time(NULL));

    while(i<MEDICIONES)
    {
	aux.id = rand()%10;
	switch(aux.id)
        {
            case TENSION:
                aux.valor = (rand()%22000)/100.0;		//Valor de 0 a 220V con 2 decimales
                strcpy(aux.unidad, "V"); 			
                break;
            case CORRIENTE:
                aux.valor = (rand()%10000)/100.0;		//Valores de 0 a 100A con 2 decimales
                strcpy(aux.unidad, "A");
                break;
            case RESISTENCIA:
                aux.valor = (rand()%10000000);			//Valores de 0 a 10MOhm
                strcpy(aux.unidad, "OHM");
                break;
            case CAPACIDAD:
                aux.valor = (rand()%10000/10.0);		//Valores de 1nF a 1mF 
                strcpy(aux.unidad, "uF");
                break;
            case FRECUENCIA:
                aux.valor = (rand()%1000000000);		//Valores de 0 a 1GHz sin decimales
                strcpy(aux.unidad, "Hz");
                break;
            case PRESION:
                aux.valor = (rand()%2000)/10.0+1013;	//Valores de 1013HPa a 1213HPa con 1 decimal 
                strcpy(aux.unidad, "Pa");
                break;
            case FUERZA:
                aux.valor = (rand()%5000)/10.0;
                strcpy(aux.unidad, "N");			//Valores de 0 a 500N con 1 decimal
                break;
            case VELOCIDAD:
                aux.valor = (rand()%500)/10.0;			//Valores de 0 a 50m/s con 1 decimal
                strcpy(aux.unidad, "m/seg");
                break;
            case ACELERACION:
                aux.valor = (rand()%200)/10.0;			//Valores de 0 a 20m/s2 con 1 decimal
                strcpy(aux.unidad, "m/seg2");
                break;
            case LUZ:
                aux.valor = (rand()%2000)/10.0+150;		//Valores de 150 a 350Lux con 1 decimal
                strcpy(aux.unidad, "Cd");
                break;
            default:
                break;
	}
	aux.timestamp = time(NULL) + rand()%DELTAT;

        tlocal =localtime(&aux.timestamp);
        strftime(aux.output,20,"%d/%m/%Y %H:%M:%S",tlocal);
        
	fwrite(&aux, sizeof(sensor_t), 1, fp);

	i++;
    }

	fclose(fp);

    return 0;
}
