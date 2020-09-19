#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include "info1-sockets.h"

int open_tcp_server(int port) {
    int res;					// resultado de algunas funciones
    int ssock;             		// descriptor del socket del servidor
    struct sockaddr_in my_addr;	// mi direccion
	unsigned int len;			// tamanio de la direccion
    // struct hostent *hp;			// host entity information (datos del host donde estoy corriendo)
    // char hostname[128];     	// buffer para el nombre del host

    // Crea un socket del tipo sream (TCP) en el dominio INET (internet)
    ssock = socket(AF_INET, SOCK_STREAM, 0);
    if(ssock < 0){
    	perror(strerror(errno));
        return SOCKET_ERROR;
    }

    // Inicializa la direccion
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(port);
    // Utilizar cualquier interfaz de red.
    my_addr.sin_addr.s_addr = INADDR_ANY;

    // // Busca el nombre de host local
    // gethostname(hostname, sizeof(hostname));

    // // Busca en  "/etc/hosts" o pregunta al DNS (servidor de nombres de la red) */
    // hp = gethostbyname(hostname);
    // if(!hp){
    // 	perror(strerror(errno));
    //     return SOCKET_ERROR;
    // }

    // // Copia la direccion IP
    // memcpy(&my_addr.sin_addr.s_addr, hp->h_addr, hp->h_length);

    // Asigna la direcion al socket
    res = bind(ssock, (struct sockaddr *)&my_addr, sizeof(my_addr));
    if(res < 0){
    	perror(strerror(errno));
        return -1;
    }

    // Busca la direccion y puerto asignada
    len = sizeof(len);
    res = getsockname(ssock, (struct sockaddr *)&my_addr, &len);
    if(res < 0){
    	perror(strerror(errno));
        return SOCKET_ERROR;
    }

    // Muestra la direccion y el puerto. Cuidado de convertir entre los formatos network y host.
    printf("Sirviendo en %s:%d ...\n", inet_ntoa(my_addr.sin_addr), ntohs(my_addr.sin_port));

    // Espera conexiones entrantes
    listen(ssock, SOCKET_BACKLOG);

    return ssock;
}


int open_tcp_client(const char * hostname, int port) {
    int res;                    // resultado de algunas funciones
    int sock;                   // descriptor del socket
    struct sockaddr_in server;  // direccion del servidor
    struct hostent *hp;         // host entity information (datos del host donde estoy corriendo)

    // Crea un socket del tipo stream (TCP) en el dominio INET (internet)
    sock = socket(AF_INET, SOCK_STREAM, 0 );
    if(sock < 0){
        perror(strerror(errno));
        return SOCKET_ERROR;
    }

    // Inicializa la direccion
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // Busca la direccion del servidor
    hp = gethostbyname(hostname);
    if(!hp){
        perror(strerror(errno));
        return -1;
    }

    // Copia la direccion IP
    memcpy(&server.sin_addr, hp->h_addr, hp->h_length);

    // Se conecta con el servidor
    res = connect(sock, (struct sockaddr *) &server, sizeof(server));
    if(res < 0){
        perror(strerror(errno));
        return SOCKET_ERROR;
    }

    return sock;
}

int open_udp_server(int port, struct sockaddr_in * src) {
    int res;                    // resultado de algunas funciones
    int sock;                   // descriptor del socket
    struct sockaddr_in my_addr; // mi direccion
    unsigned int src_len;       // tamanio de la estructura de direccion
    // struct hostent *hp;         // host entity information (datos del host donde estoy corriendo)
    // char hostname[128];         // buffer para el nombre del host

    // crea un socket del tipo datagaram (UDP) en el dominio INET (internet)
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0){
        perror(strerror(errno));
        return -1;
    }

    // inicializa la direccion
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(port);
    my_addr.sin_addr.s_addr = INADDR_ANY;

    // // busca el nombre de host local
    // gethostname(hostname, sizeof(hostname));

    // // busca en  "/etc/hosts" o pregunta al DNS (servidor de nombres de la red) */
    // hp = gethostbyname(hostname);
    // if(!hp){
    //     perror(strerror(errno));
    //     return SOCKET_ERROR;
    // }

    // // copia la direccion IP
    // memcpy(&my_addr.sin_addr.s_addr, hp->h_addr, hp->h_length);

    // asigna la direcion al socket
    res = bind(sock, (struct sockaddr *)&my_addr, sizeof(my_addr));
    if(res < 0){
        perror(strerror(errno));
        return -1;
    }

    // busca la direccion y puerto asignada
    src_len = sizeof(*src);
    res = getsockname(sock, (struct sockaddr*)src, &src_len);
    if(res < 0){
        perror(strerror(errno));
        return SOCKET_ERROR;
    }

    // muestra la direccion y el puerto. Cuidado de convertir entre los formatos network y host
    printf(" Sirviendo en %s:%d ...\n", inet_ntoa(src->sin_addr), ntohs(src->sin_port));

    return sock;
}

int open_udp_client(const char * hostname, int port, struct sockaddr_in * dest) {
    int sock;                   // descriptor del socket
    struct hostent *hp;         // host entity information (datos del host donde estoy corriendo)

    // crea un socket del tipo datagaram (UDP) en el dominio INET (internet)
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0){
        perror(strerror(errno));
        return SOCKET_ERROR;
    }

    // inicializa la direccion
    dest->sin_family = AF_INET;
    dest->sin_port = htons(port);

    // busca la direccion del servidor
    hp = gethostbyname(hostname);
    if(!hp){
        perror(strerror(errno));
        return SOCKET_ERROR;
    }

    // copia la direccion IP
    memcpy(&(dest->sin_addr), hp->h_addr, hp->h_length);

    return sock;
}