#include <stdio.h>
#include <stdlib.h>

#define MAX 51

typedef struct{
  char naziv[MAX];
  int pbroj;
}Mesto;

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

void ucitaj_mesta(Mesto *niz, int n, FILE *f){

  for (int i = 0; i < n; i++)
    fscanf(f, "%s %d", niz[i].naziv, &niz[i].pbroj);
}

int uporedi(const void *kljuc, const void *element){

  int* x = (int*)kljuc;
  int y = ((Mesto*)element)->pbroj;

  if (*x < y){
    return -1;
  }else if (*x > y){
    return 1;
  }
  return 0;
}

int main(int argc, const char *argv[]){

  if (argc != 3)
    greska();
    
  FILE *f = fopen(argv[1], "r");
  if (NULL == f)
    greska();
    
  int broj_linija_datoteke = atoi(argv[2]);
  if (broj_linija_datoteke <= 0)
    greska();

  Mesto *niz = (Mesto*)malloc(broj_linija_datoteke * sizeof(Mesto));
  if (NULL == niz)
    greska();
    
  ucitaj_mesta(niz, broj_linija_datoteke, f);
    
  int kljuc;
  scanf("%d", &kljuc);
  if (kljuc <= 0){
    free(niz);
    greska();
  }
    
  Mesto *rez = bsearch(&kljuc, niz, broj_linija_datoteke, sizeof(Mesto), &uporedi);
  if (rez != NULL)
    printf("%s\n", rez->naziv);

  free(niz);
  fclose(f);
  return 0;
}