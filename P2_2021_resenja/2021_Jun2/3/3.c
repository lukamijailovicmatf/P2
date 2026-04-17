#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

Cvor *izbaci_elemente_koji_narusavaju_poredakk(Cvor* pocetak){

  if (pocetak == NULL || pocetak->sledeci == NULL)
    return pocetak;
    
  Cvor *prethodni = pocetak;
  Cvor *tekuci = pocetak->sledeci;

  while (tekuci != NULL){
    if (tekuci->vrednost < prethodni->vrednost){
      Cvor *tmp = tekuci;
      prethodni->sledeci = tekuci->sledeci;
      tekuci = tekuci->sledeci;
      /* prethodni ostaje isti, tekuci se izbacuje, apdejtuju se "veze" sa onim koji ide nakon tekuceg */
      free(tmp);
    }else{
      tekuci = tekuci->sledeci;
      prethodni = prethodni->sledeci;
    }
  }
  return pocetak;
}

int main(){

  Cvor *lista = NULL;
  ucitaj_listu(&lista, stdin);

  lista = izbaci_elemente_koji_narusavaju_poredakk(lista);
  ispisi_listu(lista);
    
  oslobodi_listu(lista);
  return 0;
}