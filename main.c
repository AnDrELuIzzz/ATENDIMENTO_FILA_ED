
#include "fila.h"

int main()
{
    fila f;
    inicia_fila(&f);

    int quantidade = 10;

    gera_valor(quantidade, &f);

    printf("Valores gerados:\n");
    NO *aux = f.primeiro;
}
