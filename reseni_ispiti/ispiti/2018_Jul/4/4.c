#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

Cvor* dodaj_zbir(Cvor* lista){

  if (NULL == lista || NULL == lista->sledeci)
    return lista;
    
  lista->sledeci = dodaj_zbir(lista->sledeci);

  Cvor* novi = napravi_cvor(lista->vrednost + lista->sledeci->vrednost);
  novi->sledeci = lista->sledeci;
  lista->sledeci = novi;

  return lista;
}

int main(){

  Cvor* lista = NULL;
  ucitaj_listu(&lista, stdin);

  dodaj_zbir(lista);
  ispisi_listu(lista);

  oslobodi_listu(lista);
  return 0;
}