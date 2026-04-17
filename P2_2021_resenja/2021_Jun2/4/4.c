#include <stdio.h>
#include <stdlib.h>
#include "stabla.h"

void suma_na_parnim_i_neparnim_nivoima(Cvor* koren, int nivo, int* suma_parni, int* suma_neparni){

  if (NULL == koren)
    return;

  suma_na_parnim_i_neparnim_nivoima(koren->levo, nivo + 1, suma_parni, suma_neparni);
    
  if (nivo % 2==1)
    *suma_neparni += koren->vrednost;
  else
    *suma_parni += koren->vrednost;

  suma_na_parnim_i_neparnim_nivoima(koren->desno, nivo + 1, suma_parni, suma_neparni);
}

int main(){

  Cvor *stablo = NULL;
  ucitaj_stablo(&stablo, stdin);

  int sp = 0, sn = 0;
  suma_na_parnim_i_neparnim_nivoima(stablo, 0, &sp, &sn);
  printf("%d\n", sp - sn);
    
  oslobodi_stablo(stablo);
  return 0;
}