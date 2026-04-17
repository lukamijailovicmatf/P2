#include "stabla.h"

#define MAX 100

/* vraca dimenziju niza */
int ucitaj_niz(int niz[], FILE* f){

  int i = 0;
  while (fscanf(f, "%d", &niz[i]) != EOF)
    i++;
  return i;
}

/* vraca pokazivac na element u kom se nalazi trazena vrednost, a inace NULL */
Cvor* binarna_pretraga_stabla(int kljuc, Cvor* koren){

  while (koren != NULL){
    if (kljuc == koren->vrednost)
      return koren;
        
    if (kljuc < koren->vrednost)
      koren = koren->levo;
    else
      koren = koren->desno;
  }
  return NULL;
}  

void ispisi_niz(int niz[], int n){

  for (int i = 0; i < n; i++)
    printf("%d ", niz[i]);
  putchar('\n');
}

int main(){

  FILE* fniz = fopen("niz.txt", "r");
  if (NULL == fniz)
    greska();
    
  FILE* fstablo = fopen("stablo.txt", "r");
  if (NULL == fstablo)
    greska();
    
  int niz[MAX], n;
  n = ucitaj_niz(niz, fniz);

  Cvor* stablo = NULL;
  ucitaj_stablo(&stablo, fstablo);

  for (int i = 0; i < n; i++){
    Cvor* rez_pretrage = binarna_pretraga_stabla(niz[i], stablo);
    if (rez_pretrage != NULL && rez_pretrage->desno != NULL)
        niz[i] = rez_pretrage->desno->vrednost;
  }
    
  ispisi_niz(niz, n);

  fclose(fniz);
  fclose(fstablo);
  return 0;
}