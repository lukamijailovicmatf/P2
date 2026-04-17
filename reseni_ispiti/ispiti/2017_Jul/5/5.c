#include "stabla.h"

void proizvod_cvorova_po_uslovu(Cvor* koren, int nivo, int* proizvod){

  if (NULL == koren)
    return;
    
  if (nivo % 2 == 0)
    *proizvod *= koren->vrednost;
    
  proizvod_cvorova_po_uslovu(koren->levo, nivo+1, proizvod);
  proizvod_cvorova_po_uslovu(koren->desno, nivo+1, proizvod);
}

int main(){

  FILE* f = fopen("stablo.txt", "r");
  if (NULL == f)
    greska();

  Cvor* stablo = NULL;
  ucitaj_stablo(&stablo, f);
  if (NULL == stablo){
    puts("0");
    return 0;
  }
    

  int rez = 1;
  proizvod_cvorova_po_uslovu(stablo, 0, &rez);
  printf("%d\n", rez);
    
  oslobodi_stablo(stablo);
  fclose(f);
  return 0;
}