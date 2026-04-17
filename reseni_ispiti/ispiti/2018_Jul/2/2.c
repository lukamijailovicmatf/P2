#include <stdio.h>
#include <stdlib.h>

#define MAX_IME 21
#define MAX_PREZIME 26
#define KORAK 10

typedef struct{
  char ime[MAX_IME];
  char prezime[MAX_PREZIME];
  int staz;
}Zaposleni;

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

Zaposleni* ucitaj(FILE* f, int* n){

  int alocirano = KORAK;
  Zaposleni* niz = malloc(alocirano * sizeof(Zaposleni));
  if (NULL == niz)
    greska();
    
  int i = 0;
  while (fscanf(f, "%s%s%d", niz[i].ime, niz[i].prezime, &niz[i].staz) != EOF){
    i++;
    if (i == alocirano){
      alocirano += KORAK;
      niz = realloc(niz, alocirano * sizeof(Zaposleni));
      if (NULL == niz)
        greska();
    }
  }
  *n = i;
  return niz;
}


int bin_search(Zaposleni* niz, int n, int kljuc){

  int l = 0, d = n-1;
  int s;

  while (l <= d){

    s = l + (d-l)/2;
    if (kljuc == niz[s].staz)
      return s;
        
    if (kljuc < niz[s].staz)
      d = s-1;
    else
      l = s+1;
  }
  return -1;  /* ako nema trazenog elementa */
}

int main(){

  FILE* f = fopen("zaposleni.txt", "r");
  if (NULL == f)
    greska();
    
  int n;
  Zaposleni* niz = ucitaj(f, &n);

  int kljuc;
  scanf("%d", &kljuc);
  int i = bin_search(niz, n, kljuc);

  if (i != -1){

    while (i > 0 && niz[i].staz == niz[i-1].staz)
      i--;
    printf("%s %s\n", niz[i].ime, niz[i].prezime);
    

    while (i < n && niz[i].staz == niz[i+1].staz){
      printf("%s %s\n", niz[i+1].ime, niz[i+1].prezime);   
      i++;
    } 
  }

  fclose(f);
  free(niz);
  return 0;
}