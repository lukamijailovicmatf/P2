#include "stabla.h"

void broj_cvorova_po_uslovu(Cvor* koren, int* broj){

  if (NULL == koren)
    return;
    
  if ((koren->levo != NULL && koren->levo->vrednost % 2 == 1) && (koren->desno == NULL || koren->desno->vrednost % 2 == 0)){
    (*broj)++;
  }else if ((koren->desno != NULL && koren->desno->vrednost % 2 == 1) && (koren->levo == NULL || koren->levo->vrednost % 2 == 0)){
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

  while (fscanf(f, "%d", &tmp) != EOF){    /* zbog ispitivanja ispravnosti elemenata */

    if (tmp <= 0){
      /* ako je deo stabla alociran, oslobodi */
      if (stablo != NULL){ 
        oslobodi_stablo(stablo);
      }
      greska();
   }
   dodaj_u_stablo(&stablo, tmp);
  }

  int rez = 0;
  broj_cvorova_po_uslovu(stablo, &rez);
  printf("%d\n", rez);
    
  fclose(f);
  return 0;
}