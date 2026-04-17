#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 8
#define KORAK 10

typedef struct _student{
  char k_ime[MAX];
  int dan;
  int mesec;
  int godina;
}Student;

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

Student* ucitaj(FILE* f, int* dimenzija){

  int alocirano = KORAK;
  Student* niz = malloc(alocirano * sizeof(Student));
  if (NULL == niz)
    greska();
    
  int i = 0;
  while (fscanf(f, "%s %d %d %d", niz[i].k_ime, &niz[i].dan, &niz[i].mesec, &niz[i].godina) != EOF){
    if (niz[i].dan < 1 || niz[i].dan > 31 || niz[i].mesec < 1 || niz[i].mesec > 12 || niz[i].godina < 0){
      free(niz);  /* zbog memory leak */
      greska();
    }
    i++;
    if (i == alocirano){
      alocirano += KORAK;
      niz = realloc(niz, alocirano * sizeof(Student));
      if (NULL == niz)
        greska();
  }
  *dimenzija = i;
  return niz;
}

void ispisi(const Student* niz, int n){

  for (int i = 0; i < n; i++)
    printf("%s\n", niz[i].k_ime);
}

int uporedi(const void* a, const void* b){

  Student* x = (Student*)a;
  Student* y = (Student*)b;

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

  if (strcmp(x->k_ime, y->k_ime) > 0){
    return 1;
  }else if (strcmp(x->k_ime, y->k_ime) < 0){
    return -1;
  } 
  return 0;
}

int main(){

  FILE* f = fopen("studenti.txt", "r");
  if (NULL == f)
    greska();
    
  int n;
  Student* niz = ucitaj(f, &n);

  qsort(niz, n, sizeof(Student), &uporedi);
  ispisi(niz, n);

  free(niz);
  fclose(f);
  return 0;
}

