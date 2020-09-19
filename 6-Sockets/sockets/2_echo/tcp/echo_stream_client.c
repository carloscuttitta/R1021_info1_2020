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
    char buf[1024];				// buffer de recepcion
    int nb;						// cantidad de bytes recibidos

	// verifica los argumentos de la linea de comandos
    if(ac != 4){
        printf("invocar %s <ip_o_nombre_servidor> <puerto_servidor> <mensaje>\n", av[0]);
        return -1;
    }

    sock = open_tcp_client(av[1], atoi(av[2]));

	write(sock, av[3], strlen(av[3]) );			// envia el mensaje
    memset(buf, 0, sizeof(buf));				// limpia el buffer para prepararlo para la recepcion
    nb = read(sock, buf, sizeof(buf));			// lee los bytes recibidos
    printf("data: (%s) [%d bytes]\n", buf, nb);	// muestra el mensaje recibido
    close(sock);								// cierra el socket

	return 0;
}
