#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "../../lib/info1-sockets.h"

int main(int ac, char *av[]){
    int sock;             		// descriptor del socket
    struct sockaddr_in src;		// direccion realmente asignada
    unsigned int src_len; 		// tamanio de la estructura de direccion
    struct hostent *hp;			// host entity information (datos del host donde estoy corriendo)
    char buf[512];          	// buffer de recepcion
    int nb;                 	// bytes recibidos

	// verifica los argumentos de la linea de comandos
	if(ac !=2){
		printf("invocar %s <port_donde_servir>\n", av[0]);
		return -1;
	}

    sock = open_udp_server(atoi(av[1]), &src);

    // muestra el mensaje recibido hasta que encuentra un 'chau!'
    do {
        src_len = sizeof(src);
        nb = recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr*)&src, &src_len);

        // busca el nombre del cliente
        hp = gethostbyaddr((char *)&src.sin_addr, sizeof(src.sin_addr), AF_INET);
        if(!hp){
            perror(strerror(errno));
            return -1;
        }

        buf[nb] = '\0';
        printf("data: (%s) ", buf);

        // muestra la direccion y el puerto del cliente
        printf("from: %s(%s):%d ...\n", hp->h_name, inet_ntoa(src.sin_addr), ntohs(src.sin_port));

        // manda el eco
		sendto(sock, buf, strlen(buf), 0, (struct sockaddr*)&src, sizeof(src));


    }while(strcmp(buf,"chau!"));

    // cierra el socket
    close(sock);

	return 0;
}
