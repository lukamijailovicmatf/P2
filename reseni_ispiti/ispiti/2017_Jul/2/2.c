#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 16
#define KORAK 10
#define TEKUCA_GOD 2022

typedef struct{
  char sifra[MAX];
  int dan;
  int mesec;
  int godina;
}Ispit;

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

Ispit* ucitaj(int* pn, FILE* f){

  int alocirano = KORAK;
  Ispit* niz = malloc(alocirano * sizeof(Ispit));
  if (NULL == niz)
    greska();

  int i = 0;
  while (fscanf(f, "%s %d %d %d", niz[i].sifra, &niz[i].dan, &niz[i].mesec, &niz[i].godina) == 4){
    if (niz[i].dan <= 0 || niz[i].dan > 31 || niz[i].mesec <= 0 || niz[i].mesec > 12 || niz[i].godina > TEKUCA_GOD)
      greska();
        
    i++;
    if (i == alocirano){
      alocirano += KORAK;
      niz = realloc(niz, alocirano * sizeof(Ispit));
      if (NULL == niz)
        greska();
    }
  }
    
  *pn = i;
  return niz;
}

void ispisi_sifre(Ispit* niz, int n){
  for (int i = 0; i < n; i++)
    printf("%s ", niz[i].sifra);
  putchar('\n');
}

int uporedi(const void* a, const void* b){

  Ispit* x = (Ispit*)a;
  Ispit* y = (Ispit*)b;
    
  if (x->godina > y->godina){
    return 1;
  }else if (x->godina < y->godina){
    return -1;
  }
    
  if (x->mesec > y->mesec){
    return 1;
  }else if (x->mesec < y->mesec){
    return -1;
  }
    
  if (x->dan > y->dan){
    return 1;
  }else if (x->dan < y->dan){
    return -1;
  }

  if (strcmp(x->sifra, y->sifra) < 0){
    return 1;
  }else if (strcmp(x->sifra, y->sifra) > 0){
    return -1;
  }

  return 0;
}

int main(){

  FILE* f = fopen("ispiti.txt", "r");
  if (NULL == f)
    greska();
    
  int n;
  Ispit* niz = ucitaj(&n, f);

  qsort(niz, n, sizeof(Ispit), &uporedi);
  ispisi_sifre(niz, n);

  free(niz);
  return 0;
}