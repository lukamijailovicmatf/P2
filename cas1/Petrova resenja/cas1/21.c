#include <stdio.h>
#include <stdlib.h>



int main(){

  int n;
  int *niz;
  printf("Unesite dimenziju niza: \n");
  scanf("%d", &n);
  niz=(int *)malloc(n*sizeof(int));
  if(niz==NULL){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
  }
  printf("Unesite elemente niza: \n");
  for(int i=0;i<n;i++){
    scanf("%d", &niz[i]);
  }
  printf("Ispisujemo elemente u obrnutom poretku: \n");
  for(int i=n-1;i>=0;i--){
    printf("%d ", niz[i]);
  }
  printf("\n");

  return 0;
}
