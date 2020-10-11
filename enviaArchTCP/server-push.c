#include <signal.h>
#include "defs.h"		// Mis propias definiciones

void usuario(int signum) {
  // imprime el nro de signal que recibe y sale bien del programa.
  printf("Recibida signal de usuario: %d\n", signum);
  exit (SUCCESS);
}


int main (int argc, char ** argv) {
	
    int result, size;
    int socketfd, clientfd;
    socklen_t client_length;
    struct sockaddr_in server_addr, client_addr;

// Buffer para mandar y recibir datos
    char buffer[BUFFER_SIZE];
    char fnrecv[90];
    char filename[100];
    FILE * dest;

    signal(SIGUSR1, usuario);

// verifica los argumentos de la linea de comandos
    if(argc !=2){
        printf("invocar %s <port_donde_servir>\n", argv[0]);
        return -1;
    }

// Abre un socket
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if(!socketfd) {
        perror("Error al abrir socket");
        exit(ERROR);
    }

// Preparo la estructura de direccionamiento del server
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));
    memset((void *) &(server_addr.sin_zero), '\0', 8); // Poner a cero el resto de la estructura

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
    printf("Servidor conectado en puerto %d\n",atoi(argv[1]));
	
// Y cuando llega una conexion...
    client_length = sizeof(client_addr);
    printf("Proceso servidor pid: %d\n",getpid() );

    while(1) { 
        clientfd = accept(socketfd, (struct sockaddr *) &client_addr, &client_length);
        if(clientfd<0) {
            perror("Error recibiendo conexion");
            exit(ERROR);
        }
			
// recibe el nombre del archivo
        read(clientfd, fnrecv, 90);

// Construye un nombre de archivo y lo abre
        sprintf(filename, "sent/%s", fnrecv);
        dest = fopen(filename, "r");
        printf("Solicitando archivo '%s'\n", filename);
        if(dest == NULL) {
            write(clientfd, "ER", 3);
            printf("El archivo pedido %s es invalido\n", filename);
        }
        else {
            write(clientfd, "OK", 3);
            size = 0;
            while((result = fread(buffer, 1, BUFFER_SIZE, dest))) {
                size += result;
                if(result>0) {
                    write(clientfd, buffer, result);
                }
            }
            printf("Enviados %d bytes de '%s' hacia el socket\n", size, filename);
            fclose(dest);
        }
// Cierra socket al terminar
        close(clientfd);
    }
//    close(socketfd);      la señal SIGUSR1 hace el exit(0) 
//    return SUCCESS;
}


