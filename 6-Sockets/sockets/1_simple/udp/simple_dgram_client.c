#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "../../lib/info1-sockets.h"

int main(int ac, char *av[]){
    int sock;					// descriptor del socket
    struct sockaddr_in dest; 	// direccion del destinatario
    int nb;						// cantidad de bytes transmitidos

	// verifica los argumentos de la linea de comandos
    if(ac != 4){
        printf("invocar %s <ip_o_nombre_servidor> <puerto_servidor> <mensaje>\n", av[0]);
        return -1;
    }

    sock = open_udp_client(av[1], atoi(av[2]), &dest);

	// transmite el mensaje
    nb = sendto(sock, av[3], strlen(av[3])+1, 0, (struct sockaddr*)&dest, sizeof(dest));
    printf("sendto: (%s) [%d bytes]\n", av[3], nb);

    // cierra el socket
    close(sock);

	return 0;
}
