#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int **alociraj_i_ucitaj_matricu(int n, int m){

  int **a = (int*)malloc(n * sizeof(int *));
  if (NULL == a)
    greska();
    
  for (int i = 0; i < n; i++){
    a[i] = malloc(m * sizeof(int));
    if (NULL == a[i]){
      free(a);
      greska();
    }
  }
    
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++)
      scanf("%d", &a[i][j]);
    }
    return a;
}

int maksimum_minimuma_kolona(int **a, int n, int m){

  int max = INT_MIN;
  for (int j = 0; j < m; j++){
    int min = INT_MAX;
    for (int i = 0; i < n; i++){
      if (min > a[i][j])
        min = a[i][j];
    }
 
    if (max < min)
      max = min;
  }
  return max;    
}

void oslobodi_matricu(int **a, int n){

  for (int i = 0; i < n; i++)
    free(a[i]);
  free(a);
}

int main(){

  int n, m;
  scanf("%d %d", &n, &m);
  if (n <= 0 || m <= 0)
    greska();
    
  int **matrica = alociraj_i_ucitaj_matricu(n, m);
  printf("%d\n", maksimum_minimuma_kolona(matrica, n, m));

  oslobodi_matricu(matrica, n);
  return 0;
}