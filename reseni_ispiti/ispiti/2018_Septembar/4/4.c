#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "liste.h"

void ispisi_dva_najmanja(const Cvor* lista){

  if (NULL == lista) /* ako je lista prazna */
    return;

  if (NULL == lista->sledeci){    /* ako lista ima samo jedan element */
    printf("%d\n", lista->vrednost);
    return;
  }
    
  int min = INT_MAX, min_sl = INT_MAX;

  while (lista != NULL){

    if (min > lista->vrednost){
      min_sl = min;
      min = lista->vrednost;
    }else if (min_sl > lista->vrednost){
      min_sl = lista->vrednost;
    }
    lista = lista->sledeci;
  }
  printf("%d %d\n", min, min_sl);
}

int main(){

  FILE* f = fopen("lista.txt", "r");
  if (NULL == f)
    greska();
    
  Cvor* lista = NULL;
  ucitaj_listu(&lista, f);

  ispisi_dva_najmanja(lista);

  oslobodi_listu(lista);
  fclose(f);
  return 0;
}