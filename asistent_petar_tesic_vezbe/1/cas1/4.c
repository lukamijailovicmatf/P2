#include <stdio.h>
#include <stdlib.h>

int main(){
  
  int n;
  int m;
  FILE* in=fopen("matrice.txt", "r");
  if(in==NULL){
    fprintf(stderr,"FOPEN!\n");
    exit(EXIT_FAILURE);
  }
  // ucitavamo broj redova i kolona matrice
  fscanf(in, "%d %d", &n, &m);
  int matrix[n][m];
  //ucitavamo elemente matrice
  for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
        fscanf(in, "%d", &matrix[i][j]);
     }
  }
  int k1;
  int k2;
  for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
        int sum=0;
        for(k1=i-1;k1<=i+1;k1++){
           for(k2=j-1;k2<=j+1;k2++){
              if(k1<0 || k1>n || k2<0 || k2>m)
                continue;
              if(k1==i && k2==j)
                continue;
              sum+=matrix[k1][k2];    
           }
        }
        if(sum==matrix[i][j]){
          printf("(%d, %d, %d)\n", i, j, matrix[i][j]);
        }
     }
  }
  fclose(in);

  return 0;
}
