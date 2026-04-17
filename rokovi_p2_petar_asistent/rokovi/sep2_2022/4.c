#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stabla.h"

int max=0;

void obilazak(Cvor *glava){

  if(glava==NULL)
    return;
    
  if(glava->levo==NULL && glava->desno==NULL)
    return;

  if(glava->levo!=NULL && abs(glava->vrednost-glava->levo->vrednost)>max)
    max=abs(glava->vrednost-glava->levo->vrednost);
     

  if(glava->desno!=NULL && abs(glava->vrednost-glava->desno->vrednost)>max)
    max=abs(glava->vrednost-glava->desno->vrednost);
    
  obilazak(glava->levo);
  obilazak(glava->desno);  
}

int main(){

  Cvor *glava=NULL;
  int x;
  while(scanf("%d", &x)!=EOF)
    dodaj_u_stablo(&glava, x);
    
  obilazak(glava);
  printf("%d\n", max);

  return 0;
}