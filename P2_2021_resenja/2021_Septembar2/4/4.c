#include <stdio.h>
#include <stdlib.h>
#include "stabla.h"

int broj_cvorova_pocev_od_nivoa_k(Cvor *koren, int k, int trenutni_nivo){

  if (koren == NULL)
    return 0;

  int br_cvorova_levo = broj_cvorova_pocev_od_nivoa_k(koren->levo, k, trenutni_nivo+1);
  int br_cvorova_desno = broj_cvorova_pocev_od_nivoa_k(koren->desno, k, trenutni_nivo+1);

  if (trenutni_nivo >= k)
    return br_cvorova_levo + br_cvorova_desno + 1;
  else
    return br_cvorova_levo + br_cvorova_desno;
}

int main(){

  int k;
  scanf("%d", &k);
  if (k < 0)
    greska();
    
  Cvor *stablo = NULL;
  ucitaj_stablo(&stablo, stdin);

  printf("%d\n", broj_cvorova_pocev_od_nivoa_k(stablo, k, 0));

  oslobodi_stablo(stablo);
  return 0;
}