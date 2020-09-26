#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILS 4
#define COLS 4

void llenar(char t[FILS][COLS]);
void imprimir(char t[FILS][COLS]);
void imprimir2(char t[FILS][COLS]);

int main (void) {
	char tabla[FILS][COLS];

    srandom(time(NULL));

	llenar(tabla);
	
	imprimir(tabla);
	
	imprimir2(tabla);
	
	return 0;
}

// ----------------------------------------
void llenar(char t[FILS][COLS]) {
	int i,j;

	for(i=0;i<FILS;i++) {
		for(j=0;j<COLS;j++) {
			t[i][j] = random() % 2;
		}
	}
}

// ----------------------------------------
void imprimir(char t[FILS][COLS]) {
	int i, j;
	for(i=0;i<FILS;i++) {
        for(j=0;j<COLS;j++) {
            printf("[%d][%d]=%d\t", i, j, t[i][j]);
        }
		printf("\n");
    }
	printf("\n");
}


// ----------------------------------------
void imprimir2(char t[FILS][COLS]) {
	int i, j;
	for(i=0;i<FILS;i++) {
        for(j=0;j<COLS;j++) {
            printf("%c\t", t[i][j] ? '#' : '~' );
        }
		printf("\n");
    }
	printf("\n");
}

