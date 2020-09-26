#include <stdio.h>
//-----------------------------------------------------
int  mi_strlen(char s[]);
void mi_strcpy(char destino[], char fuente[]);
void mi_strcat(char destino[], char fuente[]);

//-----------------------------------------------------
int main(void){
	char a[100], b[100], c[100];
	// ingreso de strings
	printf("a > ");	
	gets(a);
	printf("b > ");	
	gets(b);
	
	// prueba de mi_strlen
	printf("a es \"%s\" y su longitud es %d\n", a, mi_strlen(a));
	printf("b es \"%s\" y su longitud es %d\n", b, mi_strlen(b));
	
	// prueba de mi_strcpy
	mi_strcpy(c, a);
	printf("c es \"%s\" y su longitud es %d\n", c, mi_strlen(c));
	
	// prueba de mi_strcat
	mi_strcat(c, b);
	printf("c es \"%s\" y su longitud es %d\n", c, mi_strlen(c));
	 
	return 0;
}

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














