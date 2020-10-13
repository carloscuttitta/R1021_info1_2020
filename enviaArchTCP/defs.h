#include <stdio.h>		// Standard I/O
#include <stdlib.h> 	        // Libreria standard de C, para usar exit()
#include <unistd.h>		// Unix standard, para usar close()
#include <arpa/inet.h>	        // Estructuras para sockets
#include <string.h>		// Para usar strlen() y strcmp()
#include <netdb.h>		// Para usar gethostbyname()

#define ERROR 1
#define SUCCESS 0

// Server parameters
#define PORT 19876
#define BACKLOG 5

// Buffer size
#define BUFFER_SIZE 255
