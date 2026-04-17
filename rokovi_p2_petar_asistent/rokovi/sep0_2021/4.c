#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stabla.h"

int sum_of_nodes=0;

int obilazak(Cvor *glava1, Cvor *glava2){
    if(glava1==NULL && glava2==NULL)
      return 1;
    
    if(glava1==NULL || glava2==NULL)
      return 0;  

    int flag1;
    int flag2;
    
    sum_of_nodes+=glava1->vrednost+glava2->vrednost;

    flag1=obilazak(glava1->levo, glava2->desno);
    if(flag1==0)
      return 0;

    flag2=obilazak(glava1->desno, glava2->levo);
    return flag2;    
}

int main(){

    Cvor *glava=NULL;
    int x;
    while(scanf("%d", &x)!=EOF){
        dodaj_u_stablo(&glava, x);
    }

    if(glava==NULL){
        printf("Stabla su simetricna!\n");
        printf("Suma svih cvorova iznosi: 0.\n");
        exit(EXIT_FAILURE);
    } 

    sum_of_nodes+=glava->vrednost;    
    int flag=obilazak(glava->levo, glava->desno);

    if(flag){
        printf("Stabla su simetricna!\n");
        printf("Suma svih cvorova iznosi: %d.\n", sum_of_nodes);
    } else {
        printf("Stabla nisu simetricna!\n");
        printf("-1\n");
    }


    oslobodi(glava);

    return 0;
}