#include <stdio.h>
#include <stdlib.h>
#include "stabla.h"

void broj_cvorova_po_uslovu(Cvor* koren, int* broj){

  if (NULL == koren)
    return;
    
  if (koren->vrednost % 2 == 0){

    if (koren->desno != NULL)
      (*broj)++;

    if (koren->levo != NULL)
      (*broj)++;
  }
  broj_cvorova_po_uslovu(koren->levo, broj);
  broj_cvorova_po_uslovu(koren->desno, broj);
}

int main(){

  FILE* f = fopen("stablo.txt", "r");
  if (NULL == f)
    greska();
    
  Cvor* stablo = NULL;
  int tmp;

  while (fscanf(f, "%d", &tmp) != EOF){       /* zbog provere ispravnosti elemenata */

    if (tmp <= 0){

      if (stablo != NULL){   /* ako je deo stabla alociran, oslobodi */

        oslobodi_stablo(stablo);
      }
      greska();
    }
    dodaj_u_stablo(&stablo, tmp);
  }

    int rez = 0;
    broj_cvorova_po_uslovu(stablo, &rez);
    printf("%d\n", rez);

    oslobodi_stablo(stablo);
    fclose(f);   
    return 0;
}
