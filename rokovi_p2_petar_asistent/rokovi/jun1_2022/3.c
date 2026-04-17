#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void izmeni_listu(Cvor **lista, int k, int p){

   if(*lista==NULL)
     return;
   
   if((*lista)->sledeci==NULL)
     return;
   
   if(abs((*lista)->vrednost+(*lista)->sledeci->vrednost)%k==p){
      Cvor *novi1=napravi_cvor(0);
      Cvor *novi2=napravi_cvor(0);
      Cvor *tmp=(*lista)->sledeci;
      (*lista)->sledeci=novi1;
      novi1->sledeci=novi2;
      novi2->sledeci=tmp;
      izmeni_listu(&(*lista)->sledeci->sledeci->sledeci, k, p);
      return;
   }

   izmeni_listu(&(*lista)->sledeci, k, p);
}

int main(){

    Cvor *lista=NULL;
    int k;
    int p;
    scanf("%d %d", &k, &p);

    lista=ucitaj_listu(lista, stdin);
    izmeni_listu(&lista, k, p);
    ispisi_listu(lista);

    oslobodi_listu(lista);

    return 0;
}