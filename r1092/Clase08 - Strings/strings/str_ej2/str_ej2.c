#include <stdio.h>
//-----------------------------------------------------
void imprime_string(char s[]);

//-----------------------------------------------------
int main(void){
	char a[] = {'h', 'o', 'l', 'a', '\0'};
	char b[] = "hola";

	imprime_string(a);
	
	putchar('\n');
	
	imprime_string(b);

	return 0;
}
//-----------------------------------------------------
void imprime_string(char s[]){
	int i;
	for(i=0; s[i]; i++){
		printf("%c %d 0x%02x\n", s[i], s[i], s[i]);
	}		
}

