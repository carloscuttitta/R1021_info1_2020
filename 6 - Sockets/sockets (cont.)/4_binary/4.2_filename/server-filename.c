#include <stdio.h>		// Standard I/O
#include <sys/types.h>	// Tipos y estructuras
#include <sys/socket.h>	// Sockets
#include <stdlib.h> 	// Libreria standard de C, para usar exit()
#include <unistd.h>		// Unix standard, para usar close()
#include <netinet/in.h>	// Estructuras para sockets
#include <strings.h>	// Para usar bzero()
#include "defs.h"		// Mis propias definiciones

int main (int argc, char ** argv) {
	
	int result, size;
	int socketfd, clientfd, port;
	socklen_t client_length;
	struct sockaddr_in server_addr, client_addr;

	// Buffer para mandar y recibir datos
	char buffer[BUFFER_SIZE];
	char fnrecv[255];
	char filename[255];
	FILE * dest;

	// Obtiene el numero de puerto, sino pone el default
	port = (argc<2) ? PORT : atoi(argv[1]);

	// Abre un socket
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	
	if(!socketfd) {
		perror("Error al abrir socket");
		exit(ERROR);
	}

	// Preparo la estructura de direccionamiento del server
	bzero((char*) &server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(port);

	// Vincula el socket con el puerto
	result = bind(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
	if(result<0) {
		perror("Error al bindear socket");
		exit(ERROR);
	}

	// Se pone a esperar conexiones que lleguen a ese puerto
	result = listen(socketfd, BACKLOG);
	if(result<0) {
		perror("Error intentando escuchar en puerto");
		exit(ERROR);
	}

	printf("Servidor conectado en puerto %d\n", port);
	
	// Y cuando llega una conexion...
	client_length = sizeof(client_addr);
	while(1) { 
		clientfd = accept(socketfd, (struct sockaddr *) &client_addr, &client_length);

		if(clientfd<0) {
			perror("Error recibiendo conexion");
			exit(ERROR);
		}
			
		// Construye un nombre de archivo y lo abre
		read(clientfd, fnrecv, 255);
		sprintf(filename, "recv/%s", fnrecv);
		dest = fopen(filename, "w");
		if(dest == NULL) {
			perror("No se puede abrir el archivo de salida");
			exit(ERROR);
		}

		size = 0;
		while((result = read(clientfd, buffer, BUFFER_SIZE))) {
			size += result; 
			if(result>0) {
				fwrite(buffer, 1, result, dest);
			}
		}
		printf("Recibidos %d bytes desde el socket, guardado en %s\n", size, filename);
		fclose(dest);

		// Cierra socket al terminar
		fflush(stdout);
		close(clientfd);
	}
	close(socketfd);

	return SUCCESS;
}
