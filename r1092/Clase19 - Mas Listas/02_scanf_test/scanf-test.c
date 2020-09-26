#include <stdio.h>


int main (int ac, char ** av) {

	char bi[50];
	char bt[500];

	FILE * fp;

	fp = fopen(av[1], "r");

	while(!feof(fp)) {
		fscanf(fp, "%13c;%[a-zA-Z0-9(), -]\n", bi, bt);
        bi[13] = '\0';
		printf("ISBN: %s, TITULO: %s\n", bi, bt);
	}

	fclose(fp);

	return 0;

}
