/*
Napisati program koji uˇcitava niz celih brojeva iz datoteke brojevi.txt sve do unosa broja 0,
koriste ́ci funkciju za realokaciju memorije sa korakom k (koji se zadaje kao argument komandne linije). Na
standardni izlaz ispisati sve brojeve koji su ve ́ci od srediˇsnjeg elementa niza. U sluˇcaju parne dimenzije
niza, srediˇsnji element raˇcunati kao aritmetiˇcku sredinu dva elementa najbliˇza sredini. U sluˇcaju greˇske na
standardni izlaz za greˇske ispisati -1.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
 
 if(argc!=2){
   greska();
 }
 int k=atoi(argv[1]);
 FILE *in=fopen("brojevi.txt", "r");
 if(in==NULL)
   greska();
  
 int n=k;
 int *niz=(int*)malloc(n*sizeof(int));
 if(niz==NULL)
   greska();
   
 int i=0;
 int x;
 while(1){
    fscanf(in, "%d", &x);
    if(x==0)
      break;
    if(i>=n){
      niz=(int *)realloc(niz, (n+k)*sizeof(int));
      if(niz==NULL)
        greska();
      n=n+k;  
    }
    niz[i]=x;
    i++;  
 }
 n=i;
 if(n%2==0){
   for(i=0;i<n;i++){
      if(niz[i]>(niz[n/2]+niz[n/2-1])/2)
        printf("%d ", niz[i]);
   }
   printf("\n");
 } else {
   for(i=0;i<n;i++){
      if(niz[i]>niz[n/2])
        printf("%d ", niz[i]);
   }
   printf("\n");
 }
   
   
 free(niz); 
 
 fclose(in); 

 return 0;
}
