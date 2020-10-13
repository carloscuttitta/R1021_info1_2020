#include "defs.h"		// Mis propias definiciones

// Abre un socket cliente apuntando a host:port
int client_socket_open(char *host, int port);


// se invoca ./client <filename> <host> <port>

int main (int argc, char ** argv) {
	
    int result, size;
    FILE * src;
    char host[255], filename[90], ack[3], fn[100];
    int socketfd, port;
	
// Buffer para mandar y recibir datos
    char buffer[BUFFER_SIZE];

// verifica los argumentos de la linea de comandos
    if(argc !=3){
        printf("invocar %s < IP > <port_donde_servir>\n", argv[0]);
        return -1;
    }
        
    // Copia el host y el puerto
    strcpy(host, argv[1]);
    port = atoi(argv[2]);

// Abre un socket
    socketfd = client_socket_open(host, port);

    size = 0;
// Lee listado desde el socket 
    while((result=read(socketfd, buffer, BUFFER_SIZE))) {
        size += result;
        fwrite(buffer, 1, result, stdout);
        if (result != BUFFER_SIZE){
            break;
        }
    }
    printf("Recibimos %d bytes desde el socket\n", size);
    
// Escribe el nombre del archivo
    printf("elija un archivo !!\n");
    scanf("%s",filename);
    write(socketfd, filename, 90);

// Lee el acknowledge
    read(socketfd, ack, 3);

    if(!strcmp(ack, "OK")) {
// Abre el archivo pedido
        sprintf(fn, "recv/%s", filename);
        src = fopen(fn, "w");
        if(src==NULL) {
            perror("Error al abrir el archivo de origen");
            exit(ERROR);
        }

        size = 0;
// Lee archivo del socket y lo guarda localmente
        while((result=read(socketfd, buffer, BUFFER_SIZE))) {
            size += result;
            fwrite(buffer, 1, result, src);
        }
        printf("Recibimos %d bytes de %s desde el socket\n", size, filename);
        fclose(src);
    }
    else {
        printf("Archivo invalido %s en el socket\n", filename);
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
    server_addr.sin_family = AF_INET;
// copia la direccion IP
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(port);
    memset((void *) &(server_addr.sin_zero), '\0', 8); // Poner a cero el resto de la estructura
	
// Intento conectarme al servidor
    result = connect(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if(result<0) {
        perror("Error conectandose al servidor");
        exit(ERROR);
    }

    return socketfd;	
}

