#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void izmeni_listu(Cvor **glava){
    if(*glava==NULL)
      return;

    if((*glava)->sledeci==NULL)
      return;

    if((*glava)->vrednost>(*glava)->sledeci->vrednost){
       Cvor *tmp=(*glava)->sledeci;
       (*glava)->sledeci=tmp->sledeci;
       tmp->sledeci=NULL;
       free(tmp);
       izmeni_listu(&(*glava));
       return; 
    }

    izmeni_listu(&(*glava)->sledeci);      
}

int main(){

    Cvor *glava=NULL;

    glava=ucitaj_listu(glava, stdin);
    izmeni_listu(&glava);

    ispisi_listu(glava);

    oslobodi_listu(glava);

    return 0;
}