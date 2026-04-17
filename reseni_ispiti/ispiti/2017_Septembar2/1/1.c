#include <stdio.h>
#include <stdlib.h>

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}


int* ucitaj_niz(const char* src[], int n){

  int* niz = malloc(n * sizeof(int));
  if (NULL == niz)
    greska();
    
  for (int i = 0; i < n; i++)
    sscanf(src[i+1], "%d", &niz[i]);
    // niz[i] = atoi(src[i]);
    
  return niz;
}

void ispisi(int* niz, int n){

  for (int i = 0; i < n; i++)
    printf("%d ", niz[i]);
  putchar('\n');
}

int strogo_rastuci(int* niz, int n){

  for (int i = 0; i < n-1; i++)
    if (niz[i] >= niz[i+1])
      return 0;
  return 1;
}

int strogo_opadajuci(int* niz, int n){

  for (int i = 0; i < n-1; i++)
    if (niz[i] <= niz[i+1])
      return 0;
  return 1;
}

int svi_jednaki(int* niz, int n){

  for (int i = 0; i < n-1; i++)
    if (niz[i] != niz[i+1])
      return 0;
  return 1;
}

int rezultat(int* niz, int n){

  if (svi_jednaki(niz, n))
    return 0;
    
  if (strogo_rastuci(niz, n)){

    int rez = 0;
    for (int i = 0; i < n; i++)
      rez += niz[i];
    return rez;
  }
    
  if (strogo_opadajuci(niz, n)){

    int rez = 1;
    for (int i = 0; i < n; i++)
      rez *= niz[i];
    return rez;
  }
  return '-';
}

int main(int argc, const char* argv[]){

  if (argc == 1)
    greska();

  int n = argc - 1;
  int* niz = ucitaj_niz(argv, n);
    
  int rez = rezultat(niz, n);

  //ispisi(niz, n);

  if (rez == '-')
    printf("-\n");
  else
    printf("%d\n", rez);

  free(niz);
  return 0;
}