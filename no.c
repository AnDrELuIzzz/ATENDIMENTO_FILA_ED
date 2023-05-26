#include <stdio.h>
#include <stdlib.h>
#include "no.h"


NO* aloca_no(int i){
  NO* novo = (NO*) malloc(sizeof(NO));

  if(novo != NULL){
    novo->info = i;
    novo->proximo = NULL;
  }
  return novo;
}
