#include <stdio.h>

#include "mi_string.h"

//-----------------------------------------------------
int main(void){
	char a[100], b[100], c[100];
	int x;
	
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
	 
	// prueba de mi_strcmp
	x = mi_strcmp(a, b);
	if(x==0)
		puts("son iguales");
	else if(x>0)
		puts("estan desordenados");
	else
		puts("estan ordenados");
	
	return 0;
}

