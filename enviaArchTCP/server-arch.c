#include <signal.h>

#include <sys/types.h>          // usado para obtener nombres de archivos
#include <dirent.h>             // usado para obtener nombres de archivos

#include "defs.h"		// Mis propias definiciones

void usuario(int signum) {
  // imprime el nro de signal que recibe y sale bien del programa.
  printf("Recibida signal de usuario: %d\n", signum);
  exit (SUCCESS);
}

void interrumpir(int signum) {
  // Ctrl-C o kill -SIGINT [pid]
  // Static define una variable que mantiene su valor en múltiples invocaciones de la función.
  // Por más que lo inicialice con un valor, dicha inicializacion sucede una vez sola.
  static int count = 5;

  if (count > 0) {
    printf("Terminando en %d\n", count);
    count --;
  }
  else {
    // Termino "limpiamente" mi programa
    // Cierro archivos, conexiones, etc.
    exit(signum);
  }
}

void terminar(int signum) {
  // Termino mi programa
  // kill -SIGTERM [PID]
  printf("!!! Hachazo !!!\n");
  exit(signum);
}


int listar_archivos(void);

int main (int argc, char ** argv) {
	
    int                 result, size;
    int                 socketfd, clientfd;
    socklen_t           client_length;
    struct sockaddr_in  server_addr, client_addr;

// Buffer para mandar y recibir datos
    char buffer[BUFFER_SIZE];
    char fnrecv[90];
    char filename[100];
    FILE * dest;
    FILE *fd_txt;

    signal(SIGUSR1, usuario);
    signal(SIGINT, interrumpir); 
    signal(SIGTERM, terminar); 

// verifica los argumentos de la linea de comandos
    if(argc !=2){
        printf("invocar %s <port_donde_servir>\n", argv[0]);
        return -1;
    }

// Abre un socket
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if(!socketfd) {
        perror("Error al abrir socket");
        exit(ERROR);
    }

// Preparo la estructura de direccionamiento del server
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));
    memset((void *) &(server_addr.sin_zero), '\0', 8); // Poner a cero el resto de la estructura

// Vincula el socket con el puerto
    result = bind(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if(result<0) {
        perror("Error al bindear socket");
        exit(ERROR);
    }

// Se pone a esperar conexiones que lleguen a ese puerto
    result = listen(socketfd, BACKLOG);
    if(result<0) {
        perror("Error intentando escuchar en puerto");
        exit(ERROR);
    }
    printf("Servidor conectado en puerto %d\n",atoi(argv[1]));
	
// Y cuando llega una conexion...
    client_length = sizeof(client_addr);
    printf("Proceso servidor pid: %d\n",getpid() );

// guardo en listado.txt los nombres de los archivos que tengo disponible para servir    
    listar_archivos();

// abro el archivo para enviarle al cliente el nombre de los archivos que puedo servir    
    fd_txt = fopen( "listado.txt" , "r" );
    if( fd_txt==0 ){
        printf("ERROR - no se creo el archivo de salida \n");
        exit(1);
    }
    
    while(1) { 
        clientfd = accept(socketfd, (struct sockaddr *) &client_addr, &client_length);
        if(clientfd<0) {
            perror("Error recibiendo conexion");
            exit(ERROR);
        }
        size = 0;
        while((result = fread(buffer, 1, BUFFER_SIZE, fd_txt))) {
            size += result;
            if(result>0) {
                write(clientfd, buffer, result);
            }
        }
        printf("Enviados %d bytes de '%s' hacia el socket\n", size, "listado.txt");
        fclose(fd_txt);
			
// recibe el nombre del archivo
        read(clientfd, fnrecv, 90);

// Construye un nombre de archivo y lo abre
        sprintf(filename, "sent/%s", fnrecv);
        printf("Solicitando archivo '%s'\n", filename);
        dest = fopen(filename, "r");
        if(dest == NULL) {
            write(clientfd, "ER", 3);
            printf("El archivo pedido %s es invalido\n", filename);
        }
        else {
            write(clientfd, "OK", 3);
            size = 0;
            while((result = fread(buffer, 1, BUFFER_SIZE, dest))) {
                size += result;
                if(result>0) {
                    write(clientfd, buffer, result);
                }
            }
            printf("Enviados %d bytes de '%s' hacia el socket\n", size, filename);
            fclose(dest);
        }
// Cierra socket al terminar
        close(clientfd);
    }
//    close(socketfd);      la señal SIGUSR1 hace el exit(0) 
//    return SUCCESS;
}


int listar_archivos(void)
{
    char *token;
    char cadena[100];
    FILE *fd_txt1;

/* Con un puntero a DIR abriremos el directorio */
    DIR *dir;
/* en *ent habrá información sobre el archivo que se está "sacando" a cada momento */
    struct dirent *ent;
/* Empezaremos a leer en el directorio actual */
    dir = opendir ("./sent");
/* Miramos que no haya error */
    if (dir == NULL){
        printf("No puedo abrir el directorio");
        exit(1);
    }
    fd_txt1 = fopen( "listado.txt" , "w" );
    if( fd_txt1==0 ){
        printf("ERROR - no se creo el archivo de salida \n");
        exit(1);
    }
/* Leyendo uno a uno todos los archivos que hay */
    while ((ent = readdir (dir)) != NULL){
/* Nos devolverá el directorio actual (.) y el anterior (..), como hace ls */
        if ( ( strcmp(ent->d_name, ".") !=0 ) && (strcmp(ent->d_name, "..")!=0) ){
            strcpy(cadena,ent->d_name);
            token = strtok(ent->d_name, ".");
            if( (token != NULL) && ( (strcmp(cadena,token) != 0) ) ){
                fprintf(fd_txt1,"%s\n",cadena);   
            }
        }
    }
    fclose(fd_txt1);
    closedir (dir);
    return 0;
}


