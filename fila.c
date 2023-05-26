#include "fila.h"

void inicia_fila(fila *f)
{
  f->primeiro = NULL;
  f->ultimo = NULL;
  f->tamanho = 0;
}

int esta_vazia(fila *f)
{
  return f->tamanho == 0;
}

void enfilera(int i, fila *f)
{
  NO *novo = aloca_no(i);
  if (esta_vazia(f))
  {
    f->primeiro = novo;
  }
  else
  {
    f->ultimo->proximo = novo;
  }
  f->ultimo = novo;
  f->tamanho++;
}

int desenfilera(fila *f)
{
  int aux_int = f->primeiro->info;
  NO *aux_no = f->primeiro;
  f->primeiro = f->primeiro->proximo;
  f->tamanho--;
  if (esta_vazia(f))
  {
    f->ultimo = NULL;
  }
  free(aux_no);
  return aux_int;
}

int verifica_tamanho(fila *f)
{
  return f->tamanho;
}

int consulta_primeiro(fila *f)
{
  return f->primeiro->info;
}

void exibe_fila(fila *f)
{
  if (esta_vazia(f))
  {
    printf("fila vazia\n");
  }
  else
  {
    NO *runner = f->primeiro;
    while (runner != NULL)
    {
      printf("|%d|->", runner->info);
      runner = runner->proximo;
    }

    printf("\n");
  }
}

int verifica_valor(int i, fila *f)
{
  NO *aux = f->primeiro;

  while (aux != NULL)
  {
    if (aux->info == i)
    {
      return 1;
    }
    aux = aux->proximo;
  }
  return 0;
}

void gera_valor(int insere_n, fila *f)
{
  inicia_fila(&f);
  srand(time(0));
  while (insere_n > 0)
  {
    int info = rand() % 50;
    if (verifica_valor(f, info))
    {
      enfilera(f, info);
      insere_n--;
    }
  }
}

void atendimento(fila *f)
{
  while (!esta_vazia(f))
  {
    int menor_valor = f->primeiro->info;
    NO *no_atual = f->primeiro;
    NO *no_anterior = NULL;
    NO *anterior_menor = NULL;

    while (no_atual != NULL)
    {
      if (no_atual->info < menor_valor)
      {
        menor_valor = no_atual->info;
        anterior_menor = no_anterior;
      }

      no_anterior = no_atual;
      no_atual = no_atual->proximo;
    }

    printf("Atendimento: %d\n", menor_valor);

    if (anterior_menor == NULL)
      f->primeiro = f->primeiro->proximo;
    else
      anterior_menor->proximo = anterior_menor->proximo->proximo;

    free(no_atual);

    if (f->primeiro == NULL)
      f->ultimo = NULL;
  }
}