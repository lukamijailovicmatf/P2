#include <stdio.h>
#include <stdlib.h>

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

void ucitaj(int *niz_manje_jednakih, int *niz_vecih, int *dim1, int *dim2, int br_elemenata, int x, FILE *f){

  int brojac1 = 0;
  int brojac2 = 0;
  int tmp;

  while (brojac1 + brojac2 < br_elemenata){
    fscanf(f, "%d", &tmp);
    if (tmp > x){
      niz_vecih[brojac1] = tmp;
      brojac1++;
    }else{
      niz_manje_jednakih[brojac2] = tmp;
      brojac2++;
    }
  }
  *dim1 = brojac1;
  *dim2 = brojac2;
}

int uporedi_vece(const void *a, const void *b){

  int x = *(int *)a;
  int y = *(int *)b;

  if (x < y){
    return -1;
  }else if (x > y){
    return 1;
  } 
  return 0;
}

int uporedi_manje_jednake(const void *a, const void *b){

  int x = *(int *)a;
  int y = *(int *)b;

  if (x > y){
    return -1;
  }else if (x < y){
    return 1;
  }
  return 0;
}

void ispisi(int *niz, int n){

  for (int i = 0; i < n; i++)
    printf("%d ", niz[i]);
  putchar('\n');
}

int main(int argc, const char *argv[]){

  if (argc != 3)
    greska();

  FILE *ulaz = fopen(argv[1], "r");
  if (NULL == ulaz)
    greska();

  int x = atoi(argv[2]);

  int *niz_vecih_od_x; 
  int *niz_manje_jednakih_od_x;
  
  int n;
  fscanf(ulaz, "%d", &n);
  if (n <= 0)
    greska();
    
  niz_vecih_od_x = malloc(n * sizeof(int));
  if (NULL == niz_vecih_od_x)
    greska();

  niz_manje_jednakih_od_x = malloc(n * sizeof(int));
  if (NULL == niz_manje_jednakih_od_x){
    free(niz_vecih_od_x);
    greska();
  }
    
  int n_vecih;
  int n_manje_jednakih;
  ucitaj(niz_manje_jednakih_od_x, niz_vecih_od_x, &n_vecih, &n_manje_jednakih, n, x, ulaz);

  qsort(niz_vecih_od_x, n_vecih, sizeof(int), &uporedi_vece);
  qsort(niz_manje_jednakih_od_x, n_manje_jednakih, sizeof(int), &uporedi_manje_jednake);

  ispisi(niz_manje_jednakih_od_x, n_manje_jednakih);  
  ispisi(niz_vecih_od_x, n_vecih);
    
  fclose(ulaz);
  free(niz_vecih_od_x);
  free(niz_manje_jednakih_od_x);
  return 0;
}