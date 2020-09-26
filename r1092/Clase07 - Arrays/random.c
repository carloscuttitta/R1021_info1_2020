#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_posta(int a, int b) {
	return random()%(1+b-a) + a;
}

int main(void) {
	srandom(time(NULL));
	printf("%d\n", random_posta(0,100));
	printf("%d\n", random_posta(100,5000));
	printf("%d\n", random_posta(47,630));
}