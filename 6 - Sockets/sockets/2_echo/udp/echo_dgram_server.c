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
# include <errno.h>

int main(int ac, char *av[]){
    int res;					// resultado de algunas funciones
    int sock;             		// descriptor del socket
    struct sockaddr_in my_addr;	// mi direccion
    struct sockaddr_in src;		// direccion realmente asignada
    unsigned int src_len; 		// tamanio de la estructura de direccion
    struct hostent *hp;			// host entity information (datos del host donde estoy corriendo)
    char hostname[128];     	// buffer para el nombre del host
    char buf[512];          	// buffer de recepcion
    int nb;                 	// bytes recibidos

	// verifica los argumentos de la linea de comandos
	if(ac !=2){
		printf("invocar %s <port_donde_servir>\n", av[0]);
		return -1;
	}

    // crea un socket del tipo datagaram (UDP) en el dominio INET (internet)
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0){
    	perror(strerror(errno));
        return -1;
    }
    
    // inicializa la direccion
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(atoi(av[1]));

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
    
    // asigna la direecion al socket
    res = bind(sock, (struct sockaddr *)&my_addr, sizeof(my_addr));
    if(res < 0){
    	perror(strerror(errno));
        return -1;
    }

    // busca la direccion y puerto asignada
    src_len = sizeof(src);
    res = getsockname(sock, (struct sockaddr *)&src, &src_len);
    if(res < 0){
    	perror(strerror(errno));
        return -1;
    }
    
    // muestra la direccion y el puerto. Cuidado de convertir entre los formatos network y host
    printf(" sirviendo en %s:%d ...\n", inet_ntoa(src.sin_addr), ntohs(src.sin_port));


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
