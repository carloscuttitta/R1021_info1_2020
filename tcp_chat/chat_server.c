#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

// la busco con: curl -s ifconfig.me

int main(int ac, char *av[]){
    int res,i;				// resultado de algunas funciones
    int ssock;             		// descriptor del socket del servidor
    int csock;             		// descriptor del socket del cliente
    struct sockaddr_in my_addr;	        // mi direccion
    struct sockaddr_in cl_addr;	        // direccion del cliente
    unsigned int len;			// tamanio de la direccion
    char buf[1024];			// buffer de recepcion

// verifica los argumentos de la linea de comandos
	if(ac !=2){
		printf("invocar %s <port_donde_servir>\n", av[0]);
		return -1;
	}
// crea un socket del tipo stream (TCP) en el dominio INET (internet)
    if ( (ssock = socket(AF_INET, SOCK_STREAM, 0)) < 0 ){
    	perror(strerror(errno));
        return -1;
    }
// inicializa la direccion
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(atoi(av[1]));
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    //  my_addr.sin_addr.s_addr = inet_addr("192.168.0.65");

 //Avisar al sistema que se creo un socket
    if ( (res = bind( ssock, (struct sockaddr *)&my_addr, sizeof(my_addr) ) ) == -1){
    	perror(strerror(errno));
        return -1;
    }
// muestra la direccion y el puerto. Cuidado de convertir entre los formatos network y host
    printf(" sirviendo en %s:%d ...\n", inet_ntoa(my_addr.sin_addr), ntohs(my_addr.sin_port));
// espera conexiones entrantes
    if ( listen(ssock, 5) == -1 ){
    	perror(strerror(errno));
        return -1;
    }
        
    while(1){
// acepta la conexion entrante
        len = sizeof(my_addr);
        if ( (csock = accept(ssock, (struct sockaddr *)&cl_addr, &len)) == -1 ){
            perror(strerror(errno));
            return -1;
        }
        printf(" conectado desde %s:%d ...\n", inet_ntoa(cl_addr.sin_addr), ntohs(cl_addr.sin_port));
// hasta recibir un mensaje 'chau!'
        while(1){
            memset(buf, 0, sizeof(buf));	// limpia el buffer de recepcion (lo llena con ceros)
            read(csock, buf, sizeof(buf));  	// lee el mensaje
            printf("--- %s\n", buf);
            if(!strcmp(buf,"chau!"))            // si recibe "chau!" cierra la conexion
                break;
            if(!strcmp(buf,"cerrar!")){         // si recibe "chau!" cierra la conexion y sale
// cierra el socket del servidor
                close(ssock);
                return 0;
            }
            printf(">>> ");
            fgets(buf,sizeof(buf),stdin);       // lee respuesta del teclado
            for (i=0;buf[i]!='\0';i++){         // lo uso para buscar el valor de i donde está el null
            }     
            buf[i-1]='\0';      // elimino el salto de linea que escribió en nombre corriendo el null
            write(csock, buf, strlen(buf)+1);   // envia respuesta
        }
// cierra la conexion
        close(csock);
    }
// cierra el socket del servidor
    close(ssock);
    return 0;
}
