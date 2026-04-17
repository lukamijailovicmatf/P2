#include "stabla.h"

int sirina_nivoa_stabla(Cvor* koren, int nivo){

  if (NULL == koren)
    return 0;
    
  if (nivo == 0)
    return 1;
  else
    return sirina_nivoa_stabla(koren->levo, nivo-1) + sirina_nivoa_stabla(koren->desno, nivo-1);
}

int dubina_stabla(Cvor* koren){

  if (NULL == koren)
    return 1;
    
  int dubina_levo = dubina_stabla(koren->levo);
  int dubina_desno = dubina_stabla(koren->desno);

  if (dubina_levo > dubina_desno)
    return dubina_levo+1;
  else
    return dubina_desno+1;
}

int main(){

  FILE* f = fopen("stablo.txt", "r");
  if (NULL == f)
    greska();
    
  Cvor* stablo = NULL;
  ucitaj_stablo(&stablo, f);

  int max = 0;
  int sirina_nivoa;
  int dubina = dubina_stabla(stablo);
  for (int i = 0; i < dubina; i++){
    sirina_nivoa = sirina_nivoa_stabla(stablo, i);
    if (max < sirina_nivoa)
      max = sirina_nivoa;
  }
  printf("%d\n", max);

  fclose(f);
  return 0;
}