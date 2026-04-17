#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

/* Cvor* izbaci(Cvor* lista, int prethodni){

  if (NULL == lista || NULL == lista->sledeci)
    return lista;
    
  Cvor* rez = lista;

  if (lista->vrednost < prethodni + lista->sledeci->vrednost){
    prethodni = lista->vrednost;
    rez = lista->sledeci;
    free(lista);
    rez = izbaci(rez, prethodni);
  }else{
    prethodni = rez->vrednost;
    rez->sledeci = izbaci(rez->sledeci, prethodni);
  }
  return rez;
} */

Cvor* izbaci(Cvor* lista){

  if (NULL == lista || NULL == lista->sledeci || NULL == lista->sledeci->sledeci)
    return lista;

  Cvor* rez = lista;
    
  while (NULL != lista->sledeci->sledeci){
    if (lista->sledeci->vrednost < lista->vrednost + lista->sledeci->sledeci->vrednost){
        Cvor* tmp = lista->sledeci;
        lista->sledeci = lista->sledeci->sledeci;
        free(tmp);
    }else{
        lista = lista->sledeci;
    }
  }
  return rez;
}

int main(){

  Cvor* lista = NULL;
  ucitaj_listu(&lista, stdin);

  if (lista != NULL)
    lista->sledeci = izbaci(lista->sledeci, lista->vrednost);
    
  ispisi_listu(lista);

  oslobodi_listu(lista);    
  return 0;
}