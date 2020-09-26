// Info1 - Sockets

// Libreria wrapper para funciones de sockets.
// Se asumen generalidades para simplificar el uso de conexiones.


#define SOCKET_ERROR -1
#define SOCKET_BACKLOG 5

// Abre un server TCP en el puerto especificado
int open_tcp_server(int port);
// Conecta un cliente TCP en el host y puerto especificado
int open_tcp_client(const char * hostname, int port);

