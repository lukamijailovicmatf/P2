#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int provera(int *niz, int n, int p, int x){

   if(p>0 && p<n-1){
     return abs(niz[p]-x)<=abs(niz[p-1]-x) && abs(niz[p]-x)<abs(niz[p+1]-x);
   }else if(p==0) {
     return abs(niz[p]-x)<abs(niz[p+1]-x);
   }else {
     return abs(niz[p]-x)<=abs(niz[p-1]-x);
   }
}

int binarna(int *niz, int n, int x){

   int l=0;
   int r=n-1;
   int s;
   while(l<=r){
     s=l+(r-l)/2;
     if(provera(niz, n, s, x))
       return s;
     else if(niz[s]<x)
       l=s+1;
     else if(x<niz[s])
       r=s-1;    
   }
   return -1;
}

int main(){
  
  int n;
  int *niz;
  int x;
  printf("Unesite dimenziju niza:\n");
  scanf("%d", &n);
  if(n<=0)
    greska();
    
  niz=(int*)malloc(n*sizeof(int));
  if(niz==NULL)
    greska();
  
  printf("Unesite elemente niza: \n");
  for(int i=0;i<n;i++)
     scanf("%d", &niz[i]);
  
  printf("Unesite element za pretragu: \n");
  scanf("%d", &x);
  
  printf("\n--------------------------------\n");
  int k=binarna(niz, n, x);
  printf("BINARNA: %d.\n", niz[k]); 
  
  free(niz);    

  return 0;
}
