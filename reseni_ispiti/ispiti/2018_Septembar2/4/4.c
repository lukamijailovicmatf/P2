#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int ima_vise_jedinica(int x){

  unsigned mask = 1 << (8*sizeof(unsigned) - 1);
  int br_jed = 0, br_nul = 0;

  while (mask){
    if (x & mask)
      br_jed++;
    else
      br_nul++;
    mask >>= 1;
  }

  if (br_jed > br_nul)
    return 1;

  return 0;   
}

Cvor* izbaci(Cvor* lista){

  if (NULL == lista)
    return NULL;
    
  if (ima_vise_jedinica(lista->vrednost)){
    Cvor* tmp = lista;
    lista = lista->sledeci;
    free(tmp);
    lista = izbaci(lista);
  }else
    lista->sledeci = izbaci(lista->sledeci);

  return lista;
}

int main(){

  Cvor* lista = NULL;
  ucitaj_listu(&lista, stdin);

  lista = izbaci(lista);
  ispisi_listu(lista);
    
  oslobodi_listu(lista);
  return 0;
}