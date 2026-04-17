#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

Cvor* parni_elementi(Cvor* lista){

  if (NULL == lista || NULL == lista->sledeci)
    return lista;
    
  if (lista->vrednost % 2 == 0 && lista->sledeci->vrednost % 2 == 0){

    int broj = lista->vrednost + lista->sledeci->vrednost;
    Cvor* novi = napravi_cvor(broj);

    novi->sledeci = lista;
    lista = novi;

    novi->sledeci->sledeci = parni_elementi(novi->sledeci->sledeci);
    return lista;
  }else{
    lista->sledeci = parni_elementi(lista->sledeci);
    return lista;
  }
}

int main(){

  FILE* f = fopen("lista.txt", "r");
  if (NULL == f)
    greska();
    
  Cvor* lista = NULL;
  ucitaj_listu(&lista, f);
  fclose(f);

  Cvor* rez_lista = parni_elementi(lista);

  ispisi_listu(rez_lista);
  oslobodi_listu(rez_lista);
    
  return 0;
}