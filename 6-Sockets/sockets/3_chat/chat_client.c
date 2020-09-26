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
#include "info1-sockets.h"

int main(int ac, char *av[]){
    int sock,i;             		// descriptor del socket
    char buf[1024];				// buffer de recepcion
    char cerrar[]={"cerrar!"};
    char chau[]={"chau!"};
    
	// verifica los argumentos de la linea de comandos
    if(ac != 3){
        printf("invocar %s <ip_o_nombre_servidor> <puerto_servidor>\n", av[0]);
        return -1;
    }

    sock = open_tcp_client(av[1], atoi(av[2]));

    while(1){
        printf("...\n");
        fgets(buf,100,stdin);                          // lee mensaje del teclado


for (i=0;buf[i]!='\0';i++){
}
        buf[i-1]='\0';   // elimino el salto de linea que escribió en nombre corriendo el null
        printf("---\n ");

        write(sock, buf, strlen(buf)+1);    // envia mensaje
        if(!strcmp(buf, chau))           // si envie "chau!", cierra la conexion
        {
            printf("salgo por chau!");
            break;
        }
        if(!strcmp(buf, cerrar))         // si envie "cerrar!", cierra la conexion
        {
            printf("salgo por cerrar!");
            break;
        }    

        read(sock, buf, sizeof(buf));       // lee los bytes recibidos

        for (i=0;buf[i]!='\0';i++){
            printf("%c", buf[i]);
}
            printf("\n");
    }
    close(sock);							// cierra el socket

    return 0;
}
