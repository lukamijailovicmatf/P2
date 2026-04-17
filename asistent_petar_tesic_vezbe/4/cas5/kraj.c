#include <stdio.h>
#include <stdlib.h>

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

int skalarni_proizvod(int *a, int* b, int n){
   if(n==0)
     return 0;
   
   return a[0]*b[0]+skalarni_proizvod(a+1, b+1, n-1);  
}

void trougao1(int n, int linija){

  if(linija>n)
    return;
  
  for(int i=1;i<=linija;i++){
     printf("+");
  }
  printf("\n");
  trougao1(n, linija+1);  
} 

void trougao2(int n, int linija){

   if(linija>n)
    return;
  
  for(int i=1;i<=n-linija;i++){
     printf(" ");
  }
  for(int i=1;i<=linija;i++){
     printf("+");
  }
  printf("\n");
  
  trougao2(n, linija+1);
} 

int main(){

 int n;
 int *niz1;
 int *niz2;

 printf("Unesite pozitivan ceo broj n: \n");

 scanf("%d", &n);
 if(n<0)
   greska();
   
 niz1=(int*)malloc(n*sizeof(int));

 if(niz1==NULL)
   greska();
 
 niz2=(int*)malloc(n*sizeof(int));

 if(niz2==NULL)
   greska();
       
 printf("Unesite elemente prvog niza: \n");

 for(int i=0;i<n;i++){
    scanf("%d", &niz1[i]);
 }
 
 printf("Unesite elemente drugog niza: \n");

 for(int i=0;i<n;i++){
    scanf("%d", &niz2[i]);
 }
 printf("\n------------------------------------\n");

 printf("Skalarni proizvod nizova iznosi: %d.\n", skalarni_proizvod(niz1, niz2, n)); 

 printf("\n------------------------------------\n"); 

 printf("Ponovo unesite neki pozitivan ceo broj: \n");

 scanf("%d", &n);
 if(n<=0)
   greska();

 printf("\n------------------------------------\n"); 
 
 trougao1(n, 1);

 printf("\n------------------------------------\n");

 trougao2(n, 1);

 return 0;
}
