#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 11

typedef struct _tacka{
  float x;
  float y;
  char ime[MAX];
}Tacka;

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

void ucitaj_tacke(Tacka *niz, int n, FILE *f){

  for (int i = 0; i < n; i++){
    fscanf(f, "%f %f %s", &niz[i].x, &niz[i].y, niz[i].ime);
  }
}

void ispisi(Tacka *niz, int n){
  for (int i = 0; i < n; i++)
    printf("%g %g %s\n", niz[i].x, niz[i].y, niz[i].ime);
}

int uporedi(const void *a, const void *b){

  Tacka *x = (Tacka *)a;
  Tacka *y = (Tacka *)b;
  
  /* rastuce */
  if (x->x < y->x){
    return -1;
  }else if (x->x > y->x){
    return 1;
  }
  
  /* opadajuce */  
  if (x->y > y->y){
    return -1;
  }else if (x->y < y->y){
    return 1;
  }
  return strcmp(x->ime, y->ime);
}

int main(){

  FILE *f = fopen("tacke.txt", "r");
  if (NULL == f)
    greska();

  int n;
  fscanf(f, "%d", &n);
  if (n <= 0)
    greska();
    
  Tacka *niz = (Tacka*)malloc(n * sizeof(Tacka));
  if (NULL == niz)
    greska();

  ucitaj_tacke(niz, n, f);
    
  qsort(niz, n, sizeof(Tacka), &uporedi);
  ispisi(niz, n);

  fclose(f);
  free(niz);
  return 0;
}