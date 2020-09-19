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
#include "../../lib/info1-sockets.h"

int main(int ac, char *av[]){
    int sock;             		// descriptor del socket

	// verifica los argumentos de la linea de comandos
    if(ac != 4){
        printf("invocar %s <ip_o_nombre_servidor> <puerto_servidor> <mensaje>\n", av[0]);
        return -1;
    }

    sock = open_tcp_client(av[1], atoi(av[2]));

    if(sock==SOCKET_ERROR) {
        perror(strerror(errno));
        return SOCKET_ERROR;
    }

	write(sock, av[3], strlen(av[3]) );			// envia el mensaje
    close(sock);								// cierra el socket

	return 0;
}
