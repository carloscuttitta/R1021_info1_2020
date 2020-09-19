
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
#include "info1-sockets.h"

int main(int ac, char *av[]){
    int res,i;				// resultado de algunas funciones
    int ssock;             		// descriptor del socket del servidor
    int csock;             		// descriptor del socket del cliente
    struct sockaddr_in cl_addr;	        // direccion del cliente
    unsigned int len;			// tamanio de la direccion
    char buf[1024];			// buffer de recepcion
    char cerrar[]={"cerrar!"};
    char chau[]={"chau!"};

// verifica los argumentos de la linea de comandos
    if(ac !=2){
        printf("invocar %s <port_donde_servir>\n", av[0]);
        return -1;
    }

    ssock = open_tcp_server(atoi(av[1]));

    while(1){
// acepta la conexion entrante
        csock = accept(ssock, 0, 0);
        res = getsockname(csock, (struct sockaddr *)&cl_addr, &len);
        if(res < 0){
            perror(strerror(errno));
            return -1;
        }
        printf(" Conectado desde %s ...\n", inet_ntoa(cl_addr.sin_addr));

// hasta recibir un mensaje 'chau!'
        while(1){
//            memset(buf, 0, sizeof(buf));	// limpia el buffer de recepcion (lo llena con ceros)
            read(csock, buf, sizeof(buf));  	// lee el mensaje

for (i=0;buf[i]!='\0';i++){
            printf("%c", buf[i]);
}
            printf("\n");

//            printf("--- %s\n", buf);
            if(!strcmp(buf,chau))            // si recibe "chau!" cierra la conexion
            {
                printf("salgo por chau!");
                break;
            }
            if(!strcmp(buf,cerrar)){         // si recibe "chau!" cierra la conexion y sale
// cierra el socket del servidor
                printf("salgo por cerrar!");
                close(ssock);
                return 0;
            }
//            memset(buf, 0, sizeof(buf));	// limpia el buffer de recepcion (lo llena con ceros)
            printf(">>> ");
            fgets(buf,100,stdin);  // lee respuesta del teclado
for (i=0;buf[i]!='\0';i++){
}
        buf[i-1]='\0';   // elimino el salto de linea que escribió en nombre corriendo el null
            
            printf("---\n ");
            write(csock, buf, strlen(buf)+1);   // envia respuesta
        }

// cierra la conexion
        close(csock);
    }

// cierra el socket del servidor
    close(ssock);
    return 0;
}
