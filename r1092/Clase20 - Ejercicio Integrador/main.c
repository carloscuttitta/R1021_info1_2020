#include <stdio.h>
#include "pubsub.h"
#include "backend.h"

int main(int argc, char ** argv) {

  sub_t *L = NULL;

  unsigned int ch_a[] = {ZANAHORIA,BROCOLI,0};
  unsigned int ch_b[] = {ZANAHORIA,BROCOLI,PAPA,0};
  unsigned int ch_c[] = {ZANAHORIA,LECHUGA,BATATA,0};

  suscribir(&L, "verduleria-1", ch_a, &archivo);
  suscribir(&L, "verduleria-2", ch_b, &red);
  suscribir(&L, "verduleria-3", ch_c, &paloma_mensajera);

  publicar(L, "Aumento de precio la zanahoria", ZANAHORIA);
  publicar(L, "Se robaron un camion de lechuga", LECHUGA);
  publicar(L, "Llego un cargamento de brocoli", BROCOLI);
  publicar(L, "Sale con fritas", BATATA);

  desuscribir(&L, "verduleria-1");

  publicar(L, "Este es el mensaje final sobre las zanahorias", ZANAHORIA);

  return 0;
}