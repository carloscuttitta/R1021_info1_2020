#include <stdio.h>
//-----------------------------------------------------
void imprime_string(char s[]);

//-----------------------------------------------------
int main(void){
	char a[100];
	
	//scanf("%s", a);
	gets(a);
	
	printf("%s", a);
	putchar('\n');
	 
	puts(a);	
	putchar('\n');
	
	imprime_string(a);

	return 0;
}
//-----------------------------------------------------
void imprime_string(char s[]){
	int i;
	for(i=0; s[i]; i++){
		printf("%c %d 0x%02x\n", s[i], s[i], s[i]);
	}		
}

