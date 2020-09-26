#include "mi_string.h"

//-----------------------------------------------------
int  mi_strlen(char s[]){
	int l = 0;
	while(s[l]){
		l++;
	}
	return l;
}

//-----------------------------------------------------
void mi_strcpy(char destino[], char fuente[]){
	int i = 0;
	while(fuente[i]){
		destino[i] = fuente[i];
		i++;
	}
	destino[i] = fuente[i];
}

//-----------------------------------------------------
void mi_strcat(char destino[], char fuente[]){
	int i;
	i = mi_strlen(destino);
	mi_strcpy(&destino[i], fuente);
}

//-----------------------------------------------------
int mi_strcmp(char destino[], char fuente[]){
	int diff, i;
	i = 0;
	while(1){
		diff = (int)(destino[i] - fuente[i]);
		if (diff)
			break;
		else if(!fuente[i])
			break;
		else
			i++;
	}
	return diff;
}

