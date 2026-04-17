#include <stdio.h>
#include <stdlib.h>

#define KORAK 10

typedef struct{
  int vrednost;
  int br_delilaca;
}Broj;

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

Broj* ucitaj(int* n){

  Broj* niz = malloc(KORAK * sizeof(Broj));
  if (NULL == niz)
    greska();
    
  int i = 0;
  while (scanf("%d", &niz[i].vrednost) != EOF){
    niz[i].br_delilaca = br_pravih_delilaca(niz[i].vrednost);

    i++;
    if (i % KORAK == 0){
      Broj* tmp = realloc(niz, (i+KORAK) * sizeof(Broj));
      if (NULL == tmp){
        free(niz);
        greska();
      }
      niz = tmp;
    }
  }
  *n = i;
  return niz;
}

void ispisi(Broj* niz, int n){

  for (int i = 0; i < n; i++)
    printf("%d ", niz[i].vrednost);
  putchar('\n');
}

int br_pravih_delilaca(int x){

  int br_del = 0;
  for (int i = 2; i < x; i++){
    if (x % i == 0)
      br_del++;
  }
  return br_del;
}


int uporedi(const void* a, const void* b){

  Broj* x = (Broj*)a;
  Broj* y = (Broj*)b;

  if (x->br_delilaca < y->br_delilaca){
    return -1;
  }else if (x->br_delilaca > y->br_delilaca){
    return 1;
  }
    
  if (x->vrednost < y->vrednost){
    return -1;
  }else if (x->vrednost > y->vrednost){
    return 1;
  }
  return 0;
}

int main(){
  int n;
  Broj* niz = ucitaj(&n);

  qsort(niz, n, sizeof(Broj), &uporedi);
  ispisi(niz, n);

  free(niz);
  return 0;
}