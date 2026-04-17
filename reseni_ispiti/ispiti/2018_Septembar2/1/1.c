#include <stdio.h>
#include <stdlib.h>

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int** alociraj_i_ucitaj_matricu(int n){

  int** m = (int**)malloc(n * sizeof(int*));
  if (NULL == m)
    greska();

  for (int i = 0; i < n; i++){
    m[i] = (int*)malloc(n * sizeof(int));
    if (NULL == m[i])
      greska();
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++)
      scanf("%d", &m[i][j]);
  }
  return m; 
}

int suma_na_pozicijama(int** m, int n, int k){

  int suma = 0;

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (abs(i-j) == k)
        suma += m[i][j];
    }
  }
  return suma;
}

int main(int argc, const char* argv[]){

  if (argc != 3)
    greska();

  int n, k;
  n = atoi(argv[1]);
  k = atoi(argv[2]);

  if (n <= 0)
    greska();
    
  int** matrica = alociraj_i_ucitaj_matricu(n);
    
  printf("%d\n", suma_na_pozicijama(matrica, n, k));

  free(matrica);
  return 0;
}