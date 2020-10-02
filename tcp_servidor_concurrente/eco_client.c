#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define TAM 1024

int main(int ac, char *av[]){
    int n;				// resultado de algunas funciones
    int sock;             		// descriptor del socket
    struct sockaddr_in server;          // direccion del servidor
    struct hostent *hp;			// host entity information (datos del host donde estoy corriendo)
                                        // ver con: cat /etc/hosts
                                        // esta en <netdb.h>
                                        //struct  hostent {
                                        //  char *  h_name;     
                                        //  char ** h_aliases; 
                                        //  int     h_addrtype;  
                                        //  int     h_length;    
                                        //  char ** h_addr_list;
                                        //  };                                        
    char buf[TAM];			// buffer de recepcion

// verifica los argumentos de la linea de comandos
    if(ac != 3){
        printf("invocar %s <ip_o_nombre_servidor> <puerto_servidor>\n", av[0]);
        return -1;
    }
// crea un socket del tipo stream (TCP) en el dominio INET (internet)
    if ( (sock = socket(AF_INET, SOCK_STREAM, 0)) < 0 ){
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
    if ( (connect( sock, (struct sockaddr *) &server, sizeof(server) ) ) < 0 ){
    	perror(strerror(errno));
        return -1;
    }
    
    while (fgets(buf, TAM, stdin) != NULL) {
        if ((n = write(sock, buf, strlen(buf))) < 0) {
            perror(strerror(errno));
            exit(1);    
        }

        if ((n = read(sock, buf, TAM)) < 0) {
            perror(strerror(errno));
            exit(1);
        }       
    
        fputs(buf, stdout);
    }
    
    close(sock);			    // cierra el socket

    return 0;
}
