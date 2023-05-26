#include <stdio.h>
#include <time.h>
#include "no.h"

typedef struct
{
  NO *primeiro;
  NO *ultimo;
  int tamanho;
} fila;

void inicia_fila(fila *);
int esta_vazia(fila *);
void enfilera(int, fila *);
int desenfilera(fila *);
int verifica_tamanho(fila *);
int consulta_primeiro(fila *);
void exibe_fila(fila *);
void gera_valor(int, fila *);
int verifica_valor(int, fila *);
void atendimento(fila *);
