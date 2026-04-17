#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int zbir_narednih(Cvor* lista){

  int suma = 0;
  while (lista != NULL){
    suma += lista->vrednost;
    lista = lista->sledeci;
  }
  return suma;
}

Cvor* izbaci(Cvor* lista){

  if (NULL == lista || NULL == lista->sledeci)
    return lista;

  Cvor* rez = lista;
  if (lista->vrednost > zbir_narednih(lista->sledeci)){
    rez = lista->sledeci;
    free(lista);
    rez = izbaci(rez);
  }
  rez->sledeci = izbaci(rez->sledeci);
  return rez;
}

int main() {

  Cvor* lista = NULL;
  ucitaj_listu(&lista, stdin);
    
  Cvor* rez_lista = izbaci(lista);

  ispisi_listu(rez_lista, stdout);
  oslobodi_listu(rez_lista);
  return 0;
}