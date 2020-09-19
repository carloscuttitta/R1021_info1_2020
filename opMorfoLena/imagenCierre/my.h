#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct bmpFileHeader
{
/* 2 bytes de identificación estan aparte BM */
  unsigned int size;                /* Tamaño del archivo */
  unsigned short resv1;             /* Reservado */
  unsigned short resv2;             /* Reservado */
  unsigned int offset;              /* Offset hasta hasta los datos de imagen */
} bmpFileHeader;

typedef struct bmpInfoHeader
{
  unsigned int headersize;          /* Tamaño de la cabecera */
  unsigned int width;               /* Ancho */
  unsigned int height;              /* Alto */
  unsigned short planes;            /* Planos de color (Siempre 1) */
  unsigned short bpp;               /* bits por pixel */
  unsigned int compress;            /* compresión */
  unsigned int imgsize;             /* tamaño de los datos de imagen */
  unsigned int bpmx;                /* Resolución X en bits por metro */
  unsigned int bpmy;                /* Resolución Y en bits por metro */
  unsigned int colors;              /* colors used en la paleta */
  unsigned int imxtcolors;          /* Colores importantes. 0 si son todos */
  char ocupa[82];                   /* Reservado lo agregue pero no se que tiene */  
} bmpInfoHeader;

#define SEPARADOR   puts("+--------------------------------------+");

//FUNCIONES
void crea_nombre( char **, char *, const char *  );
void cierre ( unsigned int *imgdata , unsigned int *aux_img ,bmpInfoHeader bInfoHeader);
void erosion ( unsigned int *imgdata , unsigned int *aux_img ,bmpInfoHeader bInfoHeader);
void dilata ( unsigned int *imgdata , unsigned int *aux_img ,bmpInfoHeader bInfoHeader);
void erosion_5 ( unsigned int *imgdata , unsigned int *aux_img ,bmpInfoHeader bInfoHeader);
void dilata_5 ( unsigned int *imgdata , unsigned int *aux_img ,bmpInfoHeader bInfoHeader);
