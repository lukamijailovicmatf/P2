#include "stabla.h"

void suma_cvorova_po_uslovu(Cvor* koren, int* suma, int trenutni_nivo, int poslednji_nivo){

  if (NULL == koren)
    return;
    
  if (koren->desno == NULL && koren->levo == NULL && trenutni_nivo == poslednji_nivo)
    *suma += koren->vrednost;
    
  suma_cvorova_po_uslovu(koren->levo, suma, trenutni_nivo+1, poslednji_nivo);
  suma_cvorova_po_uslovu(koren->desno, suma, trenutni_nivo+1, poslednji_nivo);
}

int poslednji_nivo_stabla(Cvor* koren){

  if (NULL == koren)
    return 0;
    
  int poslednji_levo = poslednji_nivo_stabla(koren->levo);
  int poslednji_desno = poslednji_nivo_stabla(koren->desno);

  if (poslednji_levo < poslednji_desno)
    return poslednji_desno+1;
  else
    return poslednji_levo+1;
    
}

int main(){

  FILE* f = fopen("stablo.txt", "r");
  if (NULL == f)
    greska();
    
  Cvor* stablo = NULL;
  ucitaj_stablo(&stablo, f);

  int suma = 0;
  int poslednji_nivo = poslednji_nivo_stabla(stablo);
  suma_cvorova_po_uslovu(stablo, &suma, 1, poslednji_nivo);  
  printf("%d\n", suma);

  fclose(f);
  return 0;
}