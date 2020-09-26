#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <errno.h>


int main(int ac, char *av[]){
    int res;					// resultado de algunas funciones
    int sock;             		// descriptor del socket
    struct sockaddr_in server;	// direccion del servidor
    struct hostent *hp;			// host entity information (datos del host donde estoy corriendo)
    char buf[1024];				// buffer de recepcion
    int nb;						// cantidad de bytes recibidos

	// verifica los argumentos de la linea de comandos
    if(ac != 4){
        printf("invocar %s <ip_o_nombre_servidor> <puerto_servidor> <mensaje>\n", av[0]);
        return -1;
    }
    
    // crea un socket del tipo stream (TCP) en el dominio INET (internet)
    sock = socket(AF_INET, SOCK_STREAM, 0 );
    if(sock < 0){
    	perror(strerror(errno));
        return -1;
    }

    // inicializa la direccion
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(av[2]));
    
    // busca la direccion del servidor
    hp = gethostbyname(av[1]);
    if(!hp){
    	perror(strerror(errno));
        return -1;
    }
    
    // copia la direccion IP
    memcpy(&server.sin_addr, hp->h_addr, hp->h_length);

	// se conecta con el servidor
    res = connect(sock, (struct sockaddr *) &server, sizeof(server));
    if(res < 0){
    	perror(strerror(errno));
        return -1;
    }

	write(sock, av[3], strlen(av[3]) );			// envia el mensaje
    memset(buf, 0, sizeof(buf));				// limpia el buffer para prepararlo para la recepcion
    nb = read(sock, buf, sizeof(buf));			// lee los bytes recibidos
    printf("data: (%s) [%d bytes]\n", buf, nb);	// muestra el mensaje recibido
    close(sock);								// cierra el socket

	return 0;
}
