/*
Napisati program koji sa standardnog ulaza uˇcitava matricu celih brojeva. Prvo se uˇcitaju broj
vrsta i kolona matrice, a zatim i elementi matrice. Na standardni izlaz ispisati uˇcitanu matricu. Zatim
napisati funkciju
int sum max(int **A, int n, int m)
koja raˇcuna zbir najve ́cih elemenata u svakoj vrsti. Ispisati rezultat izvrˇsavanja funkcije na standardni izlaz.
U sluˇcaju greˇske na standardni izlaz za greˇske ispisati -1
*/
#include <stdio.h>
#include <stdlib.h>

void greska(){
  fprintf(stderr,"-1");
  exit(EXIT_FAILURE);
}

int sum_max(int **A, int n, int m){
   int sum=0;
   for(int i=0;i<n;i++){
      int max=A[i][0];
      for(int j=1;j<m;j++){
         if(A[i][j]>max)
           max=A[i][j];
      }
      sum+=max;
   }
   return sum;
}

int main(){

 int n;
 int m;
 printf("Unesite dimenzije matrice: \n");
 scanf("%d %d", &n, &m);
 int **A=(int **)malloc(n*sizeof(int *));
 if(A==NULL)
   greska();
 
 for(int i=0;i<n;i++){
    A[i]=(int *)malloc(m*sizeof(int));
    if(A[i]==NULL)
      greska();
 }
 printf("\n----------------------------------\n");
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
       scanf("%d", &A[i][j]);
    }
 }
 printf("\n----------------------------------\n");
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
       printf("%d ", A[i][j]);
    }
    printf("\n");
 }
 
 printf("%d\n", sum_max(A, n, m));
 
 for(int i=0;i<n;i++){
    free(A[i]);
 }
 free(A);
 
   

 return 0;
}
