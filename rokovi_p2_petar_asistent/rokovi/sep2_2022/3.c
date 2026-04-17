#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void rotiraj(Cvor **glava){

  if(*glava==NULL)
    return;

  if((*glava)->sledeci==NULL)
    return;

  Cvor *tmp=(*glava)->sledeci;
  (*glava)->sledeci=tmp->sledeci;
  tmp->sledeci=*glava;
  *glava=tmp;

  rotiraj(&(*glava)->sledeci->sledeci);    
}

int main(){

    Cvor *glava=NULL;
    glava=ucitaj_listu(glava, stdin);
    rotiraj(&glava);
    ispisi_listu(glava);


    oslobodi_listu(glava);

    return 0;
}