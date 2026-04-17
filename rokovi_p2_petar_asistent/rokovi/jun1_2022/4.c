#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stabla.h"

void paran_broj_suseda(Cvor *koren, Cvor *predak){

  if(koren==NULL)
    return;

  paran_broj_suseda(koren->levo, koren);
  paran_broj_suseda(koren->desno, koren);
    
  int susedi;

  if(predak!=NULL){
    susedi=1;

    if(koren->levo!=NULL)
      susedi++;

    if(koren->desno!=NULL)
      susedi++;

    if(susedi%2==0)
      printf("%d ", koren->vrednost);    
  }else{
    susedi=0;

    if(koren->levo!=NULL)
      susedi++;

    if(koren->desno!=NULL)
      susedi++;

    if(susedi%2==0)
      printf("%d ", koren->vrednost);
  }
}

int main(){

  Cvor *stablo=NULL;
  int x;
  while(scanf("%d", &x)!=EOF)
      dodaj_u_stablo(&stablo, x);

  paran_broj_suseda(stablo, NULL);
    
  oslobodi(stablo);

  return 0;
}