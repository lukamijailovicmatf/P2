#include <stdio.h>
#include <stdlib.h>
#include "stabla.h"

int jeste_simetricno(Cvor *levo, Cvor *desno){

  if ((levo == NULL && desno != NULL) || (levo != NULL && desno == NULL)){
    return 0;
  }else if (levo == NULL && desno == NULL){
    return 1;
  }
  return jeste_simetricno(levo->levo, desno->desno) * jeste_simetricno(levo->desno, desno->levo);
}

int suma_cvorova(Cvor *koren){

  if (NULL == koren)
    return 0;
    
  return koren->vrednost + suma_cvorova(koren->levo) + suma_cvorova(koren->desno);
}

int main(){

  Cvor *stablo = NULL;
  ucitaj_stablo(&stablo, stdin);

  if (stablo != NULL && jeste_simetricno(stablo->levo, stablo->desno))
    printf("%d\n", suma_cvorova(stablo));
  else
    printf("-1\n");

  oslobodi_stablo(stablo);
  return 0;
}

