#include <stdio.h>
#include <stdlib.h>

int main (void) {

	int a[20];
	int * b;

	int i,j;

	printf("Ingrese cantidad de elementos: ");
	scanf("%d", &i);

	b = (int *) malloc(sizeof(int) * i);

	for(j=0; j<i; j++) {
		b[j] = j;
		*(b+j) *= 2;
	}

	printf("a: %p, b: %p\n", a, b);

	for(j=0; j<i; j++) {
		printf("b[%d] = %d\n", j, *(b+j));
	}

	free(b);

	return 0;
}
