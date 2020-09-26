#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <errno.h>

int main(int ac, char *av[]){
    int res;					// resultado de algunas funciones
    int ssock;             		// descriptor del socket del servidor
    int csock;             		// descriptor del socket del cliente
    struct sockaddr_in my_addr;	// mi direccion
    struct sockaddr_in cl_addr;	// direccion del cliente
	unsigned int len;			// tamanio de la direccion
    struct hostent *hp;			// host entity information (datos del host donde estoy corriendo)
    char hostname[128];     	// buffer para el nombre del host
    char buf[1024];				// buffer de recepcion
    int nb;						// cantidad de bytes recibidos

	// verifica los argumentos de la linea de comandos
	if(ac !=2){
		printf("invocar %s <port_donde_servir>\n", av[0]);
		return -1;
	}

    // crea un socket del tipo sream (TCP) en el dominio INET (internet)
    ssock = socket(AF_INET, SOCK_STREAM, 0);
    if(ssock < 0){
    	perror(strerror(errno));
        return -1;
    }
    
    // inicializa la direccion
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(atoi(av[1]));
    //my_addr.sin_addr.s_addr = INADDR_ANY;
  
    // busca el nombre de host local
    gethostname(hostname, sizeof(hostname));
    
    // busca en  "/etc/hosts" o pregunta al DNS (servidor de nombres de la red) */
    hp = gethostbyname(hostname);
    if(!hp){
    	perror(strerror(errno));
        return -1;
    }

    // copia la direccion IP
    memcpy(&my_addr.sin_addr.s_addr, hp->h_addr, hp->h_length);  

    // asigna la direcion al socket 
    res = bind(ssock, (struct sockaddr *)&my_addr, sizeof(my_addr));
    if(res < 0){
    	perror(strerror(errno));
        return -1;
    }

    // busca la direccion y puerto asignada  
    len = sizeof(len);
    res = getsockname(ssock, (struct sockaddr *)&my_addr, &len);
    if(res < 0){
    	perror(strerror(errno));
        return -1;
    }
    
    // muestra la direccion y el puerto. Cuidado de convertir entre los formatos network y host
    printf(" sirviendo en %s:%d ...\n", inet_ntoa(my_addr.sin_addr), ntohs(my_addr.sin_port));

    // espera conexiones entrantes
    listen(ssock, 5);

    // hasta recibir un mensaje 'chau!'
    do{
    	csock = accept(ssock, 0, 0);		// acepta la conexion entrante
		res = getsockname(csock, (struct sockaddr *)&cl_addr, &len);
		if(res < 0){
			perror(strerror(errno));
		    return -1;
		}
	    printf(" conectado desde %s ...\n", inet_ntoa(cl_addr.sin_addr));
        memset(buf, 0, sizeof(buf));		// limpia el buffer de recepcion (lo llena con ceros)
        nb = read(csock, buf, sizeof(buf));	// lee el mensaje
        close(csock);						// cierra la conexion
        printf("data: (%s) [%d bytes]\n", buf, nb);
    }while(strcmp(buf,"chau!"));
    
    // cierra el socket del servidor
    close(ssock);
	return 0;
}
