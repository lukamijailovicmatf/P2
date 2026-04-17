#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

typedef enum{
  OK,
  NEMA_PONAVLJANJA
}Status;

Status broj_koji_se_ponavlja(Cvor* lista1, Cvor* lista2, int* rez){

  int broj;
  int min_zbir_pozicija = 0;
  int pozicija1 = 1, pozicija2;
  int jeste_break;
    
  for (; lista1 != NULL; lista1 = lista1->sledeci){
    pozicija2 = 1;
    jeste_break = 0;
    for (Cvor* p = lista2; p != NULL; p = p->sledeci){
      if (lista1->vrednost == p->vrednost){
        jeste_break = 1;
        break;
      }    
      pozicija2++;
    }
        
    if (min_zbir_pozicija){

      if (min_zbir_pozicija > pozicija1 + pozicija2){
        min_zbir_pozicija = pozicija1 + pozicija2;
        broj = lista1->vrednost;
      }

    }else if (jeste_break){
        min_zbir_pozicija = pozicija1 + pozicija2;
        broj = lista1->vrednost;
    }
    pozicija1++;
    }
    
    if (min_zbir_pozicija){
      *rez = broj;
      return OK;
    }
    return NEMA_PONAVLJANJA;
}

int main(){

  FILE* f1 = fopen("lista1.txt", "r");
  if (NULL == f1)
    greska();
    
  FILE* f2 = fopen("lista2.txt", "r");
  if (NULL == f2)
    greska();

  Cvor* lista1 = NULL;
  Cvor* lista2 = NULL;

  ucitaj_listu(&lista1, f1);
  ucitaj_listu(&lista2, f2);

  int rez;
  if (broj_koji_se_ponavlja(lista1, lista2, &rez) == OK)
    printf("%d\n", rez);

  oslobodi_listu(lista1);
  oslobodi_listu(lista2);
  fclose(f1);
  fclose(f2);
  return 0;
}