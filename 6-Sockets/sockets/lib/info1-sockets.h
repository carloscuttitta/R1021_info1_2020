// Info1 - Sockets

// Libreria wrapper para funciones de sockets.
// Se asumen generalidades para simplificar el uso de conexiones.


#define SOCKET_ERROR -1
#define SOCKET_BACKLOG 5

// Abre un server TCP en el puerto especificado
int open_tcp_server(int port);
// Conecta un cliente TCP en el host y puerto especificado
int open_tcp_client(const char * hostname, int port);

// Abre un server UDP en el puerto especificado
int open_udp_server(int port, struct sockaddr_in * src);
// Conecta un cliente UDP en el host y puerto especificado
int open_udp_client(const char * hostname, int port, struct sockaddr_in * dest);