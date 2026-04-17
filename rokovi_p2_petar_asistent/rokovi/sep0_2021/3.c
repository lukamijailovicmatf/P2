#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int prethodnici=0;
int sledbenici=0;

void izmeni_listu(Cvor** glava){
    if(*glava==NULL)
      return;
    if((*glava)->sledeci==NULL && prethodnici>sledbenici){
        sledbenici+=(*glava)->vrednost;
        (*glava)->vrednost=0;
        return;
    } else if((*glava)->sledeci==NULL){
        sledbenici+=(*glava)->vrednost;
        return;
    }
    
    prethodnici+=(*glava)->vrednost;
    izmeni_listu(&(*glava)->sledeci);
    
    prethodnici-=(*glava)->vrednost;
    
    if(prethodnici>sledbenici){
        sledbenici+=(*glava)->vrednost;
        (*glava)->vrednost=0;
    } else {
        sledbenici+=(*glava)->vrednost;
    }  
}

int main(){

    Cvor *glava=NULL;
    glava=ucitaj_listu(glava, stdin);
    izmeni_listu(&glava);
    ispisi_listu(glava);

    oslobodi_listu(glava);

    return 0;
}