#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KORAK 10
#define MAX 21

typedef struct _proizvod{
  char naziv[MAX];
  float cena;
  int kolicina;
}Proizvod;

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

Proizvod* ucitaj(int* n, FILE* f){

  int alocirano = KORAK;
  Proizvod* niz = malloc(alocirano * sizeof(Proizvod));
  if (NULL == niz)
    greska();
    
  int i = 0;
  while(fscanf(f, "%s %f %d", niz[i].naziv, &niz[i].cena, &niz[i].kolicina) != EOF){

    if (niz[i].cena < 0 || niz[i].kolicina < 0)
      greska();
        
    i++;
    if (i == alocirano){
      alocirano += KORAK;
      niz = realloc(niz, alocirano * sizeof(Proizvod));
      if (NULL == niz)
        greska();
    }
  }
  *n = i;
  return niz;
}

void ispisi(Proizvod* niz, int n){

  for (int i = 0; i < n; i++)
    printf("%s %.2f\n", niz[i].naziv, niz[i].cena * niz[i].kolicina);
}

int uporedi(const void* a, const void* b){

  Proizvod* x = (Proizvod*)a;
  Proizvod* y = (Proizvod*)b;

  if (x->cena * x->kolicina > y->cena * y->kolicina){
    return 1;
  }else if (x->cena * x->kolicina < y->cena * y->kolicina){
    return -1;
  }
    
  if (strcmp(x->naziv, y->naziv) < 0)
    return 1;
  else
    return -1;
    
}

int main(){

  FILE* f = fopen("proizvodi.txt", "r");
  if (NULL == f)
   greska();
    
  int n;
  Proizvod* niz = ucitaj(&n, f);

  qsort(niz, n, sizeof(Proizvod), &uporedi);
  ispisi(niz, n);

  fclose(f);
  free(niz);
  return 0;
}