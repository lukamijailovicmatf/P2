#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21

typedef struct _student{
  char ime[MAX];
  char prezime[MAX];
  float prosek;
}Student;

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

Student* ucitaj(int n){

  Student* niz = malloc(n * sizeof(Student));
  if (NULL == niz)
    greska();
    
  for (int i = 0; i < n; i++){
    scanf("%s%s%f", niz[i].prezime, niz[i].ime, &niz[i].prosek);
    if (niz[i].prosek > 10 || niz[i].prosek < 6){
      greska();
    }
  }
  return niz;
}

int uporedi(const void* a, const void* b){

  Student* x = (Student*)a;
  Student* y = (Student*)b;

  if (x->prosek < y->prosek){
    return 1;
  }else if (x->prosek > y->prosek){
    return -1;
  }
    
  if (strcmp(x->prezime, y->prezime) > 0){
    return 1;
  }else if (strcmp(x->prezime, y->prezime) < 0){
    return -1;
  }
    
  if (strcmp(x->ime, y->ime) < 0){
    return 1;
  }else if (strcmp(x->ime, y->ime) > 0){
    return -1;
  }
    
  return 0;
}

int main(){

  float min_prosek;
  scanf("%f", &min_prosek);
  if (min_prosek < 6 || min_prosek > 10)
    greska();

  int n;
  scanf("%d", &n);
  if (n <= 0)
    greska();
    
  Student* niz = ucitaj(n);
    
  qsort(niz, n, sizeof(Student), &uporedi);

  int i = 0;
  while (niz[i].prosek >= min_prosek && i < n){
    printf("%s %s %.2f\n", niz[i].prezime, niz[i].ime, niz[i].prosek);
    i++;
  }
    
  if (i == 0)     /* ako nema onih koji zadovoljavaju uslov */
    putchar('-');
    
  free(niz);
  return 0;
}