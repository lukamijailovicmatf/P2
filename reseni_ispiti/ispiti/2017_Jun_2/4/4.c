#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

Cvor* izbaci(Cvor* lista){

  if (NULL == lista || NULL == lista->sledeci)
    return lista;
    
  Cvor* rez = lista;
  if (lista->vrednost + lista->sledeci->vrednost == 0){
    rez = lista->sledeci;
    free(lista);
    rez = izbaci(rez);
  }
  rez->sledeci = izbaci(rez->sledeci);
  return rez;
}

int main(){

  FILE* f = fopen("lista.txt", "r");
  if (NULL == f)
    greska();

  Cvor* lista = NULL;
  ucitaj_listu(&lista, f);
  fclose(f);    

  Cvor* rez_lista = izbaci(lista);

  ispisi_listu(rez_lista);

  oslobodi_listu(rez_lista);
  return 0;
}