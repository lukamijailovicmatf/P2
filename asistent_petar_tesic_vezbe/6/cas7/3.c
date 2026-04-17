#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

int binarna(char** niz, int n, char *rec){

   int l=0;
   int r=n-1;
   int s;
   while(l<=r){
      s=l+(r-l)/2;
      if(strcmp(rec, niz[s])==0)
        return s;
      else if(strcmp(rec, niz[s])>0)
        l=s+1;
      else if(strcmp(rec, niz[s])<0)
        r=s-1;    
   }
   return -1;
}

int poredi(const void *x, const void *y){
   return strcmp((char*)x, *(char**)y);
   
}


int main(){

  int n;
  char rec[MAX];
  char **niz;
  scanf("%d", &n);
  niz=(char**)malloc(n*sizeof(char*));
  if(niz==NULL)
    greska();
  
  for(int i=0;i<n;i++){
     niz[i]=(char*)malloc(MAX*sizeof(char));
     if(niz[i]==NULL)
       greska();
  } 
  
  for(int i=0;i<n;i++){
     scanf("%s", niz[i]);
  }
  printf("\n-------------------------\n");
  scanf("%s", rec);
  printf("\n-------------------------\n");
  printf("BINARNA: %d.\n", binarna(niz, n, rec));

  /* void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)); */

  char **p=bsearch(rec, niz, n, sizeof(char*), poredi); 
  if(p==NULL)
    printf("BSEARCH: -1\n");
  else 
    printf("BSEARCH: %ld\n", p-niz);  

  for(int i=0;i<n;i++)
     free(niz[i]);
  
  free(niz);   

  return 0;
}
