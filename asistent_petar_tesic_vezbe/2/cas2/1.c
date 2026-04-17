/*
Napisati program koji sa standardnog ulaza uˇcitava dimenziju niza celih brojeva, a zatim i njegove
elemente. Ne praviti pretpostavke o dimenziji niza. Na standardni izlaz ispisati uˇcitane brojeve u obrnutom
poretku. U sluˇcaju greˇske na standardni izlaz za greˇske ispisati -1.
*/
#include <stdio.h>
#include <stdlib.h>

int main(){

 int n;
 printf("Unesite dimenziju niza: \n");
 scanf("%d", &n);
 int *niz=(int*)malloc(n*sizeof(int));
 if(niz==NULL){
   fprintf(stderr,"-1");
   exit(EXIT_FAILURE);
 }
 
 printf("Unesite elemente niza:\n");
 for(int i=0;i<n;i++){
    scanf("%d", &niz[i]);
 }
 
 for(int i=n-1;i>=0;i--){
    printf("%d ", niz[i]);
 }
 printf("\n");
 
 free(niz);
  

 return 0;
}
