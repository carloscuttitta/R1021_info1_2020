#include <stdio.h>		// Standard I/O
#include <sys/types.h>	// Tipos y estructuras
#include <sys/socket.h>	// Sockets
#include <stdlib.h> 	// Libreria standard de C, para usar exit()
#include <unistd.h>		// Unix standard, para usar close()
#include <netinet/in.h>	// Estructuras para sockets
#include <string.h>		// Para usar strlen() y strcmp()
#include <strings.h>	// Para usar bzero() y bcopy()
#include <netdb.h>		// Para usar gethostbyname()
#include "defs.h"		// Mis propias definiciones

// Abre un socket cliente apuntando a host:port
int client_socket_open(char *host, int port);

int main (int argc, char ** argv) {
	
	char host[255];
	int socketfd, port;
	
	// Buffer para mandar y recibir datos
	char buffer[BUFFER_SIZE];

    // numero ingresado
    int numero;
        
    // se invoca ./client username host <port>

    // Copia el host y el puerto
    strcpy(host, argv[2]);
    port = (argc>3) ? atoi(argv[3]) : PORT;

    while(1){
	    // Abre un socket
	    socketfd = client_socket_open(host, port);
	
	    // Lee archivo y lo manda por el socket
	    if(socketfd){
		    bzero(buffer, BUFFER_SIZE);
		    printf("numero: ");
            scanf("%d", &numero);
            if(numero > 0){
                sprintf(buffer, "%s %d", argv[1], numero);
		        write(socketfd, buffer, sizeof(buffer));
		        bzero(buffer, 255);
		        read(socketfd, buffer, 5);
		        printf("El numero secreto es %s\n", buffer);
		        if(strstr(buffer, "IGUAL")){
		            close(socketfd);
		            return SUCCESS;
		        }   
            }
	    }
	    // Cierra los sockets al terminar
	    close(socketfd);
    }
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

