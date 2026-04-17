#include <stdio.h>
#include <stdlib.h>

#define KORAK 10
#define MAX 26

typedef struct _let{
  char grad1[MAX];
  char grad2[MAX];
  float km;
  int trajanje;
}Let;

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

Let* ucitaj(int* n, FILE* f){

  int alocirano = KORAK;
  Let* niz = malloc(alocirano * sizeof(Let));
  if (NULL == niz)
    greska();
    
  int i = 0;
  while (fscanf(f, "%s %s %f %d", niz[i].grad1, niz[i].grad2, &niz[i].km, &niz[i].trajanje) != EOF){

    if (niz[i].km <= 0 || niz[i].trajanje <= 0){
      free(niz);
      greska();
    }
        
    i++;
    if (i == alocirano){
      alocirano += KORAK;
      niz = realloc(niz, alocirano * sizeof(Let));
      if (NULL == niz)
        greska();
      }
    }
    *n = i;
    return niz;
}

void ispisi(Let* niz, int n){

  for (int i = 0; i < n; i++)
    printf("%s %s %.2f %d\n", niz[i].grad1, niz[i].grad2, niz[i].km, niz[i].trajanje);
}

int uporedi(const void* a, const void* b){

  Let* x = (Let*)a;
  Let* y = (Let*)b;

  if (x->km < y->km){
    return 1;
  }else if (x->km > y->km){
    return -1;
  }
    
  if (x->trajanje > y->trajanje){
    return 1;
  }else if (x->trajanje < y->trajanje){
    return -1;
  }  
  return 0;
}

int main(){

  FILE* f = fopen("letovi.txt", "r");
  if (NULL == f)
    greska();
    
  int n;
  Let* niz = ucitaj(&n, f);

  qsort(niz, n, sizeof(Let), &uporedi);
  ispisi(niz, n);

  fclose(f);
  free(niz);
  return 0;
}