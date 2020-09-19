#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void interrumpir(int signum) {
  // Ctrl-C o kill -SIGINT [pid]
  // Static define una variable que mantiene su valor en múltiples invocaciones de la función.
  // Por más que lo inicialice con un valor, dicha inicializacion sucede una vez sola.
  static int count = 10;

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

void usuario(int signum) {
  // Simplemente imprime el nro de signal que recibe.
  printf("Recibida signal de usuario: %d\n", signum);
}

void terminar(int signum) {
  // Termino mi programa
  // kill -SIGTERM [PID]
  printf("!!! Hachazo !!!\n");
  exit(signum);
}

int main(void) {
  // Asigno el handler de la signal
  signal(SIGINT, interrumpir);
  signal(SIGTERM, terminar);
  signal(SIGUSR1, usuario);
  signal(SIGUSR2, usuario);

  printf("Mi PID es %d\n", getpid());

  while(1) {
    printf("...\n");
    sleep(1);
  }
  return 0;
}