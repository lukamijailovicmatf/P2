#include "stabla.h"

int proizvod_na_nivou(Cvor* koren, int i){

  if (NULL == koren)
    return 1;
    
  if (i == 0)
    return koren->vrednost;
    
  int proizvod_levo = proizvod_na_nivou(koren->levo, i-1);
  int proizvod_desno = proizvod_na_nivou(koren->desno, i-1);

  return proizvod_levo * proizvod_desno;
}

int main(int argc, const char* argv[]){

  if (argc != 2)
    greska();

  int nivo = atoi(argv[1]);
  if (nivo < 0)
    greska();
    
  FILE* f = fopen("stablo.txt", "r");
  if (NULL == f)
    greska();
    
  Cvor* stablo = NULL;
  ucitaj_stablo(&stablo, f);

  printf("%d\n", proizvod_na_nivou(stablo, nivo));

  oslobodi_stablo(stablo);
  return 0;
}