#include <stdio.h>
#include <stdlib.h>

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

int prethodno(int *niz, int p){
  int sum=0;
  for(int i=0;i<p;i++){
     if(niz[i]<niz[p])
       sum++;
  }
  return sum;
}

int main(){

 int n;
 
 scanf("%d", &n);
 int *niz=(int *)malloc(n*sizeof(int));
 if(niz==NULL)
   greska();
 
 for(int i=0;i<n;i++){
    scanf("%d", &niz[i]);
 }  
 
 for(int i=0;i<n;i++){
    int tmp=prethodno(niz, i);
    printf("%d ", tmp);
 }  
 free(niz);
 
 return 0;
}
