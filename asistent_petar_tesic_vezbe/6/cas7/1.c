#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

int linearna(int *niz, int n , int x){

   for(int i=0;i<n;i++){
      if(niz[i]==x)
        return i;
   }
   return -1;
}

int binarna(int *niz, int n, int x){

  int l=0;
  int r=n-1;
  int s;
  while(l<=r){
   s=l+(r-l)/2;
   /* s=(l+r)/2; */

   if(niz[s]==x)
     return s;
   else if(niz[s]<x)
     l=s+1;
   else if(x<niz[s])
     r=s-1;    
  }
   return -1;
}

int binarna_rekurzivno(int *niz, int l, int r, int x){

   if(l>r)
     return -1;
   
   int s=l+(r-l)/2;
   if(niz[s]==x)
     return s;
   else if(niz[s]<x)
     return binarna_rekurzivno(niz, s+1, r, x);
   else
     return binarna_rekurzivno(niz, l, s-1, x);      
}

int poredi(const void *a, const void *b){
   int x=*(int*)a;
   int niz_s=*(int*)b;
   return x-niz_s;
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
  printf("LINEARNA: %d.\n", linearna(niz, n, x));
  printf("BINARNA: %d.\n", binarna(niz, n, x));
  printf("REKURZIVNA BINARNA: %d.\n", binarna_rekurzivno(niz, 0, n-1, x));
  
  /* void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)); */

  int *p=bsearch(&x, niz, n, sizeof(int), &poredi);
  if(p==NULL)
    printf("BSEARCH: -1\n");
  else 
    printf("BSEARCH: %ld.\n", p-niz);  
     
  
  
  free(niz);    

  return 0;
}
