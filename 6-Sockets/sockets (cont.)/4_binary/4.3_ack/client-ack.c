#include <stdio.h>		// Standard I/O
#include <sys/types.h>	// Tipos y estructuras
#include <sys/socket.h>	// Sockets
#include <stdlib.h> 	// Libreria standard de C, para usar exit()
#include <unistd.h>		// Unix standard, para usar close()
#include <netinet/in.h>	// Estructuras para sockets
#include <string.h>		// Para usar strlen() y strcmp()
#include <strings.h>	// Para usar bzero() y bcopy()
#include <netdb.h>		// Para usar gethostbyname()
#include <libgen.h>     // Para usar basename()
#include "defs.h"		// Mis propias definiciones

// Abre un socket cliente apuntando a host:port
int client_socket_open(char *host, int port);

int main (int argc, char ** argv) {
	
	int result, size;
	FILE * src;
	char host[255], filename[255], ack[3];
	int socketfd, port;
	
	// Buffer para mandar y recibir datos
	char buffer[BUFFER_SIZE];

    // se invoca ./client filename host <port>

    // Copia el nombre del archivo 
    strcpy(filename, argv[1]);

    // Copia el host y el puerto
    strcpy(host, argv[2]);
    port = (argc>3) ? atoi(argv[3]) : PORT;

	// Abre un socket
	socketfd = client_socket_open(host, port);
	
	// Abre el archivo pedido
	src = fopen(filename, "r");
	if(src==NULL) {
		perror("Error al abrir el archivo de origen");
		exit(ERROR);
	}

	// Escribe el nombre del archivo 
	write(socketfd, basename(filename), 255);

	// Lee el acknowledge
	read(socketfd, ack, 3);

	if(!strcmp(ack, "OK")) {
	    // Lee archivo y lo manda por el socket
	    size = 0;
	    while((result=fread(buffer, 1, BUFFER_SIZE, src))) {
		    size += result;		
		    write(socketfd, buffer, result);
	    }
	    printf("Escribimos %d bytes de '%s' en el socket\n", size, filename);
	    fclose(src);
	}
	else {
		printf("Archivo invalido '%s' en el socket\n", filename);
	}

    // Cierra los sockets al terminar
    close(socketfd);

	return SUCCESS;
}

// Abre un socket cliente apuntando a host:port 
int client_socket_open(char * host, int port) {

	int result, socketfd;
    struct hostent *server;
	struct sockaddr_in server_addr;	

	// Abre un socket
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	
	// Obtiene los datos del servidor.
	server = gethostbyname(host);
	if(server == NULL) {
		perror("Error obteniendo hostname del servidor");
		exit(ERROR);
	}
	
	// Preparo los datos para conectarme al servidor
	bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&server_addr.sin_addr.s_addr,
         server->h_length);
    server_addr.sin_port = htons(port);
	
	// Intento conectarme al servidor
	result = connect(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
	if(result<0) {
		perror("Error conectandose al servidor");
		exit(ERROR);
	}

	return socketfd;	
}

