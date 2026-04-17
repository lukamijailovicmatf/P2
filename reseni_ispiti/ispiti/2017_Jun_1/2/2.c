#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21

/* Definisanje strukture za cuvanje podataka o odigranim utakmicama */

typedef struct Duel{
  char domaci[MAX];
  char gostujuci[MAX];
  int golovi_d;
  int golovi_g;
} Duel;

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

Duel* ucitaj(int n){

  Duel* niz = malloc(n * sizeof(Duel));
  if (NULL == niz)
    greska();
    
  for (int i = 0; i < n; i++){

    scanf("%s%s%d%d", niz[i].domaci, niz[i].gostujuci, &niz[i].golovi_d, &niz[i].golovi_g);
    if (niz[i].golovi_d < 0 || niz[i].golovi_g < 0){
      greska();
    }
  }
  return niz;
}

void ispisi(Duel* niz, int n){

  for (int i = 0; i < n; i++)
    printf("%s %s\n", niz[i].domaci, niz[i].gostujuci);
  
}

int uporedi(const void* a, const void* b){

  Duel* x = (Duel*)a;
  Duel* y = (Duel*)b;

  if (abs(x->golovi_d - x->golovi_g) > abs(y->golovi_d - y->golovi_g)){
    return 1;
  }else if (abs(x->golovi_d - x->golovi_g) < abs(y->golovi_d - y->golovi_g)){
    return -1;
  }
    
  /* ako su gol razlike iste */
  if (strcmp(x->domaci, y->domaci) < 0){
    return 1;
  }else if (strcmp(x->domaci, y->domaci) > 0){
    return -1;
  }
    
  /* ako su domacini isti */
  if (strcmp(x->gostujuci, y->gostujuci) > 0){
    return 1;
  }else if (strcmp(x->gostujuci, y->gostujuci) < 0){
    return -1;
  }

  /* ako je sve isto */
    return 0;
}

int main(){

  int n;
  scanf("%d", &n);
  if (n <= 0)
    greska();
    
  Duel* niz = ucitaj(n);

  qsort(niz, n, sizeof(Duel), &uporedi);

  ispisi(niz, n);

  free(niz);
  return 0;
}