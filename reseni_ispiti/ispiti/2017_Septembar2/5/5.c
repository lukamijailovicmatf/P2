#include "stabla.h"

int broj_cvorova_po_uslovu(Cvor* koren){

  if (NULL == koren)
    return 0;
    
  int rez = broj_cvorova_po_uslovu(koren->levo);
  rez += broj_cvorova_po_uslovu(koren->desno);

  if (svi_cvorovi_parni(koren))
    return rez+1;
    
  return rez;
}

int svi_cvorovi_parni(Cvor* koren){

  if (NULL == koren)
    return 1;

  int jesu_levo = svi_cvorovi_parni(koren->levo);
  int jesu_desno = svi_cvorovi_parni(koren->desno);

  if (koren->vrednost % 2)
    return 0;
    
  return jesu_desno*jesu_levo;
}

int main() {

  Cvor* stablo = NULL;
  ucitaj_stablo(&stablo, stdin);

  printf("%d\n", broj_cvorova_po_uslovu(stablo));

  oslobodi_stablo(stablo);
  return 0;
}

/*             
            6
      4            10 
    3   5        8     12
 */