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


int main(int ac, char *av[]){
    int sock;					// descriptor del socket
    struct sockaddr_in dest; 	// direccion del destinatario
    unsigned int dest_len; 		// tamanio de la estructura de direccion
    struct hostent *hp;			// host entity information (datos del host donde estoy corriendo)
    int nb;						// cantidad de bytes transmitidos o recibidos
    char buf[512];          	// buffer de recepcion

	// verifica los argumentos de la linea de comandos
    if(ac != 4){
        printf("invocar %s <ip_o_nombre_servidor> <puerto_servidor> <mensaje>\n", av[0]);
        return -1;
    }
    
    // crea un socket del tipo datagaram (UDP) en el dominio INET (internet)
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0){
    	perror(strerror(errno));
        return -1;
    }

    // inicializa la direccion
    dest.sin_family = AF_INET;
    dest.sin_port = htons(atoi(av[2]));

    // busca la direccion del servidor
    hp = gethostbyname(av[1]);
    if(!hp){
    	perror(strerror(errno));
        return -1;
    }

    // copia la direccion IP
    memcpy(&dest.sin_addr, hp->h_addr, hp->h_length);

	// transmite el mensaje
    nb = sendto(sock, av[3], strlen(av[3])+1, 0, (struct sockaddr*)&dest, sizeof(dest));
    printf("sendto: (%s) [%d bytes]\n", av[3], nb);
    
    // recibe el eco
    dest_len = sizeof(dest);
    nb = recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr*)&dest, &dest_len);
    buf[nb] = '\0';
    printf("data: (%s) [%d bytes]\n", buf, nb);
  
    // cierra el socket
    close(sock);

	return 0;
}
