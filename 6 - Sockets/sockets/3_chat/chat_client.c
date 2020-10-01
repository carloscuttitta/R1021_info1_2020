#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>


int main(int ac, char *av[]){
    int res,i;				// resultado de algunas funciones
    int sock;             		// descriptor del socket
    struct sockaddr_in server;          // direccion del servidor
    struct hostent *hp;			// host entity information (datos del host donde estoy corriendo)
    char buf[1024];			// buffer de recepcion

// verifica los argumentos de la linea de comandos
    if(ac != 3){
        printf("invocar %s <ip_o_nombre_servidor> <puerto_servidor>\n", av[0]);
        return -1;
    }
// crea un socket del tipo stream (TCP) en el dominio INET (internet)
    sock = socket(AF_INET, SOCK_STREAM, 0 );
    if(sock < 0){
    	perror(strerror(errno));
        return -1;
    }
// inicializa la direccion
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(av[2]));
// busca la direccion del servidor
    hp = gethostbyname(av[1]);
    if(!hp){
    	perror(strerror(errno));
        return -1;
    }
// copia la direccion IP
    memcpy(&server.sin_addr, hp->h_addr, hp->h_length);

// se conecta con el servidor
    res = connect(sock, (struct sockaddr *) &server, sizeof(server));
    if(res < 0){
    	perror(strerror(errno));
        return -1;
    }

    while(1){
        printf(">>> ");
        fgets(buf,sizeof(buf),stdin);                          // lee respuesta del teclado
        for (i=0;buf[i]!='\0';i++){         // lo uso para buscar el valor de i donde está el null
        }     
        buf[i-1]='\0';      // elimino el salto de linea que escribió en nombre corriendo el null
        write(sock, buf, strlen(buf)+1);    // envia mensaje
        if(!strcmp(buf, "chau!"))           // si envie "chau!", cierra la conexion
            break;
        if(!strcmp(buf, "cerrar!"))         // si envie "cerrar!", cierra la conexion
            break;

        memset(buf, 0, sizeof(buf));	    // limpia el buffer para prepararlo para la recepcion
        read(sock, buf, sizeof(buf));       // lee los bytes recibidos
        printf("--- %s\n", buf);            // muestra el mensaje recibido
    }
    close(sock);			    // cierra el socket

    return 0;
}
