#include <stdio.h>
#include <string.h>		// strcmp, strerror
#include <sys/types.h>	// open, fstat 
#include <sys/stat.h>	// open, fstat
#include <fcntl.h>		// open
#include <unistd.h>		// fstat, read, write, close 
#include <stdlib.h>		// atoi

int main (int argc, char ** argv) {

	int f;
	unsigned int i;
	int buenos, malos;
	
	f = atoi(argv[1]);
	
	buenos = open("./buenos", O_WRONLY);
	malos = open("./malos", O_WRONLY);
	
	while(1) {
		scanf("%d", &i);
		if(i>=f) {
			write(buenos, &i, sizeof(i));
			printf("Dejando pasar #%d\n", i);
			fflush(stdout);
		}
		else {
			write(malos, &i, sizeof(i));
			fprintf(stderr, "No dejo pasar al #%d\n", i);
			fflush(stderr);
		}
	}

	close(buenos);
	close(malos);
	
	return 0;
}
