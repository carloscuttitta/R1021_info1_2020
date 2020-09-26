#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void interrumpir(int signum) {
  // Ctrl-C o kill -SIGINT [pid]
  printf("Interrumpiendo el programa limpiamente...\n");
  // Cierro archivos, conexiones, etc.
  exit(signum);
}

int main(void) {
  // Asigno el handler de la signal
  signal(SIGINT, interrumpir);

  printf("Mi PID es %d\n", getpid());

  while(1) {
    printf("...\n");
    sleep(1);
  }
  return 0;
}