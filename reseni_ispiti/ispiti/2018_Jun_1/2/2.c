#include <stdio.h>
#include <stdlib.h>

#define KORAK 10

typedef struct _datum{
  int dan;
  int mesec;
  int godina;
}Datum;

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

Datum* ucitaj(FILE* f, int* dimenzija){

  int alocirano = KORAK;
  Datum* niz = malloc(alocirano * sizeof(Datum));
  if (NULL == niz)
    greska();
    
  int i = 0;
  while (fscanf(f, "%d.%d.%d.", &niz[i].dan, &niz[i].mesec, &niz[i].godina) == 3){

    if (niz[i].dan < 1 || niz[i].dan > 31 || niz[i].mesec < 1 || niz[i].mesec > 12 || niz[i].godina < 0 || niz[i].godina > 9999){
      free(niz);  /* zbog memory leak */
      greska();
    }
    i++;
    if (i == alocirano){
      alocirano += KORAK;
      niz = realloc(niz, alocirano * sizeof(Datum));
      if (NULL == niz)
        greska();
    }
  }
  *dimenzija = i;
  return niz;
}

void ispisi(Datum* niz, int n){
  for (int i = 0; i < n; i++)
    printf("%d.%d.%d.\n", niz[i].dan, niz[i].mesec, niz[i].godina);  
}

int uporedi(const void* a, const void* b){
   
  Datum* x = (Datum*)a;
  Datum* y = (Datum*)b;
    
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

  return 0; 
}

int main(){

  FILE* f = fopen("datum.txt", "r");
  if (NULL == f)
    greska();
    
  int n;
  Datum* niz = ucitaj(f, &n);

  qsort(niz, n, sizeof(Datum), &uporedi);
  ispisi(niz, n);

  free(niz);
  fclose(f);
  return 0;
}