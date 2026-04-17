#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int jeste_fibonaci(int x){

  int br1 = 1;
  int br2 = 1;
  while (br1 <= x){

    if (x == br1 || x == br2)
      return 1;
        
    int tmp = br2;
    br2 += br1;
    br1 = tmp;   
  }
  return 0;
}

Cvor* izbaci_fibonacijeve(Cvor* lista, int pozicija){

  if (NULL == lista)
    return NULL;

  if (NULL == lista->sledeci){

    if (jeste_fibonaci(pozicija)){
      free(lista);
      return NULL;
    }
    return lista;
  }
  
  Cvor* rez = lista;
  if (jeste_fibonaci(pozicija)){
    rez = lista->sledeci;
    free(lista);
    rez = izbaci_fibonacijeve(rez, pozicija+1);
  }else if (rez != NULL){
    rez->sledeci = izbaci_fibonacijeve(rez->sledeci, pozicija+1);
  }
  return rez;
} 

int main(){

  Cvor* lista = NULL;
  ucitaj_listu(&lista, stdin);

  Cvor* rez = izbaci_fibonacijeve(lista, 1);  
  ispisi_listu(rez);
    
  oslobodi_listu(rez);
  return 0;
}  