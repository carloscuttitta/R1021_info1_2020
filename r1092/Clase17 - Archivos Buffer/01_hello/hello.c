#include <stdio.h>

int main(void){
	FILE *fp;
	if((fp = fopen("hello.txt", "w")) == NULL){
		puts("ERROR!!!");
		return 1;
	}
	fprintf(fp, "Hola, mundo!\n");
	fclose(fp);
	return 0;
}
