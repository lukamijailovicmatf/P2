#include "stabla.h"
#include <math.h>

int celobrojna_vrednost_korena(double x){

  if (x - (int)x >= 0.5)
    return (int)(x+1);
  return (int)x;
}

void promeni_stablo(Cvor* koren, int vrednost_roditelja){

  if (NULL == koren)
    return;
    
  if (koren->desno != NULL && koren->desno->vrednost >= 0){

    int br = (int)sqrt(koren->desno->vrednost);
    if (koren->levo == NULL || koren->levo->vrednost < br){
      if ((koren->vrednost < vrednost_roditelja && br < vrednost_roditelja) || (koren->vrednost >= vrednost_roditelja && br >= vrednost_roditelja))
        koren->vrednost = br;
    }
  }
  promeni_stablo(koren->levo, koren->vrednost);
  promeni_stablo(koren->desno, koren->vrednost);
}

int main(){

  Cvor* stablo = NULL;
  ucitaj_stablo(&stablo, stdin);

  promeni_stablo(stablo, stablo->vrednost);
  ispisi_stablo(stablo, stdout);
  putchar('\n');

  oslobodi_stablo(stablo);
  return 0;
}