#include <stdio.h>

int main(void){
	char a[] = {'h', 'o', 'l', 'a', '\0'};
	char b[] = "hola";
	int i;

	for(i=0; a[i]; i++){
		printf("%c %d 0x%02x\n", a[i], a[i], a[i]);
	}		
	putchar('\n');	
	for(i=0; b[i]; i++){
		printf("%c %d 0x%02x\n", b[i], b[i], b[i]);
	}		

	return 0;
}
