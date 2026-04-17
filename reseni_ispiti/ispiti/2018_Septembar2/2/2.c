#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KORAK 10
#define MAX_IME 11
#define MAX_PREZIME 16

typedef struct _student{
  char ime[MAX_IME];
  char prezime[MAX_PREZIME];
  int br_p;
}Student;

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

Student* alociraj_i_ucitaj_niz(FILE* f, int* n){

  int alocirano = KORAK;
  Student* niz = malloc(alocirano * sizeof(Student));
  if (NULL == niz)
    greska();
    
  int i = 0;
  while (fscanf(f, "%s%s%d", niz[i].ime, niz[i].prezime, &niz[i].br_p) != EOF){
    i++;
    if (i == alocirano){
      alocirano += KORAK;
      Student* tmp = realloc(niz, alocirano * sizeof(Student));
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

Student* formiraj_niz(Student* niz1, Student* niz2, int n1, int n2){

  Student* rez = malloc((n1 + n2) * sizeof(Student));
  if (NULL == rez){
    free(niz1);
    free(niz2);
    greska();
  }
    
  int i = 0, j = 0, k;    /* redom brojaci za niz1, niz2, rez */
  for (k = 0; i < n1 && j < n2; k++){
    if (uporedi(niz1[i], niz2[j]) == 1){
      iskopiraj(rez, k, niz1[i]);
      i++;
    }else{
      iskopiraj(rez, k, niz2[j]);
      j++;
    }
  }

  while (i < n1)      // ako je niz2 stigao do kraja u for petlji{
    iskopiraj(rez, k, niz1[i]);
    i++;
    k++;
  }
    
  while (j < n2)      // ako je niz1 stidao do kraja u for petlji{
    iskopiraj(rez, k, niz2[j]);
    j++;
    k++;
  }
  return rez;
}

void iskopiraj(Student* niz, int i, Student tmp){

  strcpy(niz[i].ime, tmp.ime);
  strcpy(niz[i].prezime, tmp.prezime);
  niz[i].br_p = tmp.br_p;
}

void ispisi_niz(Student* niz, int n){

  for (int i = 0; i < n; i++)
    printf("%s %s %d\n", niz[i].ime, niz[i].prezime, niz[i].br_p);
}

/* vraca 1 ako prvi treba da bude pre drugog, a 2 ako je obrnut slucaj */
int uporedi(Student a, Student b){
   	
  if (a.br_p < b.br_p){
    return 1;
  }else if (a.br_p > b.br_p){
    return 2;
  }
    
  if (strcmp(a.prezime, b.prezime) < 0){
    return 1;
  }else if (strcmp(a.prezime, b.prezime) > 0){
    return 2;
  }
    
  if (strcmp(a.ime, b.ime) > 0){
    return 1;
  }else if (strcmp(a.ime, b.ime) < 0){
    return 2;
  }
    
  return 0;       // ako je sve isto
}

int main(int argc, const char* argv[]){

  if (argc != 3)
    greska();
    
  FILE* f1 = fopen(argv[1], "r");
  if (NULL == f1)
    greska();
    
  FILE* f2 = fopen(argv[2], "r");
  if (NULL == f2)
    greska();

  int n1, n2;
  Student* niz1 = alociraj_i_ucitaj_niz(f1, &n1);
  Student* niz2 = alociraj_i_ucitaj_niz(f2, &n2);

  Student* rez = formiraj_niz(niz1, niz2, n1, n2);
  ispisi_niz(rez, n1+n2);
    
  free(rez);
  free(niz1);
  free(niz2);
  fclose(f1);
  fclose(f2);
  return 0;
}



