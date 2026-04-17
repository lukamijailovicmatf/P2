#include <stdio.h>
#include <stdlib.h>

#define KORAK 10

typedef struct{
  int a;
  int b;
  int d; /* duzina intervala */
}Interval;

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

Interval* ucitaj_intervale(FILE* f, int* n){

  int alocirano = KORAK;
  Interval* niz = malloc(alocirano * sizeof(Interval));
  if (NULL == niz)
    greska();
    
  int i = 0;
  while (fscanf(f, "%d %d", &niz[i].a, &niz[i].b) != EOF){

    if (niz[i].a > niz[i].b){
      free(niz);
      greska();
    }

    niz[i].d = niz[i].b - niz[i].a;
    i++;
    if (i == alocirano){
      alocirano += KORAK;
      Interval* tmp = realloc(niz, alocirano * sizeof(Interval));
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

int uporedi_sort(const void* a, const void* b){

  Interval* x = (Interval*)a;
  Interval* y = (Interval*)b;

  if (x->d < y->d){
    return -1;
  }else if (x->d > y->d){
    return 1;
  }
    
  if (x->a > y->a){
    return -1;
  }else if (x->a < y->a){
    return 1;
  }
  return 0;   
}


int uporedi_search(const void* a, const void* b){

  int x = *(int*)a; /* posalje se zadati interval */
  Interval* y = (Interval*)b; /* ovo je niz intervala i salje se element niza i pristupa se duzini intervala u nizu */
    
  return x - y->d;
}

int main(){

  FILE* f = fopen("intervali.txt", "r");
  if (NULL == f)
    greska();
    
  int n;
  Interval* niz = ucitaj_intervale(f, &n);

  qsort(niz, n, sizeof(Interval), &uporedi_sort);
  putchar('\n');
    
  int kljuc;
  scanf("%d", &kljuc);

  Interval* rez = bsearch(&kljuc, niz, n, sizeof(Interval), &uporedi_search);
  if (rez != NULL)
    printf("%d %d\n", rez->a, rez->b);
    
  free(niz);
  fclose(f);
  return 0;
}