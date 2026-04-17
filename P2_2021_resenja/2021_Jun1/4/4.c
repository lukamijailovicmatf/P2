#include "stabla.h"

int broj_neparnih_listova(Cvor *koren){

  /* ako je stablo prazno */
  if (NULL == koren)
    return 0;
    
  if (NULL == koren->levo && NULL == koren->desno && koren->vrednost % 2 == 1)
    return 1;
    
  int br_neparnih_listova_levo = broj_neparnih_listova(koren->levo);
  int br_neparnih_listova_desno = broj_neparnih_listova(koren->desno);

  return br_neparnih_listova_levo + br_neparnih_listova_desno;
}

int main(){

  Cvor *stablo = NULL;
  ucitaj_stablo(&stablo, stdin);

  printf("%d\n", broj_neparnih_listova(stablo));

  oslobodi_stablo(stablo);
  return 0;
}

