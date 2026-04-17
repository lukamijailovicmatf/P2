#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stabla.h"

int razlika=0;

void obilazak(Cvor *glava, int level){
    if(glava==NULL)
      return;
    
    if(level%2==0)
      razlika+=glava->vrednost;
    else 
      razlika-=glava->vrednost;
    
    obilazak(glava->levo, level+1);
    obilazak(glava->desno, level+1);      
}


int main(){

    Cvor *glava=NULL;
    int x;
    while(scanf("%d", &x)!=EOF){
        dodaj_u_stablo(&glava, x);
    }
    
    obilazak(glava, 0);
    printf("%d\n", razlika);

    oslobodi(glava);

    return 0;
}