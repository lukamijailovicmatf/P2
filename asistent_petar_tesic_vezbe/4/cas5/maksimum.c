#include <stdio.h>
#include <stdlib.h>

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

int maksimum_niza(int* a, int n){
   if(n==1)
     return a[0];
     
   int tmp=maksimum_niza(a+1, n-1);
   
   return a[0] > tmp ? a[0] : tmp;  
}

int main(){

 int n;
 int *niz;
 scanf("%d", &n);
 if(n<0)
   greska();
 if(n==0)
   return 1;  
 niz=(int*)malloc(n*sizeof(int));
 if(niz==NULL)
   greska();
 
 for(int i=0;i<n;i++)
    scanf("%d", &niz[i]);
 
 printf("%d\n", maksimum_niza(niz, n));       

 return 0;
}
