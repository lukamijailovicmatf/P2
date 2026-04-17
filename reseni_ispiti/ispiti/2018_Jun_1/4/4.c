#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

Cvor* obrisi_ponavljanja(Cvor* lista){

  /* uslov za jednoclane ili prazne liste */
  if (NULL == lista || NULL == lista->sledeci)
    return lista;
    
  Cvor* rez = lista;
  if (lista->sledeci->vrednost == lista->vrednost){
    rez = lista->sledeci;
    free(lista);
    rez = obrisi_ponavljanja(rez);
  }
  rez->sledeci = obrisi_ponavljanja(rez->sledeci);
  return rez;
}

int main(){

  FILE* f = fopen("lista.txt", "r");
  if (NULL == f)
    greska();
    
  Cvor* lista = NULL;
  ucitaj_listu(&lista, f);

  Cvor* rez = obrisi_ponavljanja(lista);
  ispisi_listu(rez);

  oslobodi_listu(rez);
  fclose(f);
  return 0;
}