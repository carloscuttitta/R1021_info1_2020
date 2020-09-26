#include <stdio.h>

int enviar(char * source, char * msg) {
  printf("[Enviando x %s]: %s\n", source, msg);
  return 0;
}

int archivo(char * msg) {
  return enviar("Archivo", msg);
}

int red(char * msg) {
  return enviar("Red", msg);
}

int paloma_mensajera(char * msg) {
  return enviar("Paloma Mensajera", msg);
}