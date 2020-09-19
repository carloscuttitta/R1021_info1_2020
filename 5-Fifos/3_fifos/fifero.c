#include <stdio.h>
#include <string.h>		// strcmp, strerror
#include <sys/types.h>	// open, fstat 
#include <sys/stat.h>	// open, fstat
#include <fcntl.h>		// open
#include <errno.h>		// perror
#include <unistd.h>		// fstat, read, write, close 
#include <stdlib.h>		// atoi

int main (int argc, char ** argv) {
	int fd;
	int i, n;
	
	fd = open(argv[1], O_RDONLY);
	
	printf("Leyendo de %s...\n", argv[1]);
	
	while(1) {
		n = read(fd, &i, sizeof(i));
		if(n == sizeof(i))
			printf("%s: Recibido #%d (%d)\n", argv[1], i, n);
	}
	
	close(fd);
	
	return 0;
}
