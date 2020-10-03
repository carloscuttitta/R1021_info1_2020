#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define TAM 1024

// mi IP publica es ("181.230.115.175") y la busco con: curl -s ifconfig.me

int main(int ac, char *av[]){
    int res,nread;			// resultado de algunas funciones
    int ssock;             		// descriptor del socket del servidor
    int csock;             		// descriptor del socket del cliente
    struct sockaddr_in my_addr;	        // mi direccion
    struct sockaddr_in cl_addr;	        // direccion del cliente
    unsigned int len;			// tamanio de la direccion
    char buf[TAM];			// buffer de recepcion
    pid_t   pid;

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
        if ((pid = fork()) == 0) {
            printf("iniciando Proceso hijo pid: %d\n",getpid() );
            if (close(ssock) == -1) {
                perror(strerror(errno));
                exit(1); 
            }
            printf(" conectado desde %s:%d ...\n", inet_ntoa(cl_addr.sin_addr), ntohs(cl_addr.sin_port));

            while(1){
                if ((nread = read(csock, buf, TAM)) == 0){
                printf("saliendo del Proceso hijo pid: %d\n",getpid() );
                    break;
                }
                if ((write(csock, buf, nread)) < 0 ) {
                    perror(strerror(errno));
                    close(csock);
                    exit(1);
                }
            }
           if (close(csock) == -1) {  
                perror(strerror(errno));
                exit(1);
            }
            exit(0);
        } /* end fork */
        if (close(csock) == -1) {   // proceso padre
            perror(strerror(errno));
            exit(1);
        }
    } /* end while(1)*/
}
