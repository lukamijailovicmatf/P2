#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

int faktorijel(int n){
  if(n==0)
    return 1;
  
  return n*faktorijel(n-1);  
}

int fibonaci(int n){
   if(n==0 || n==1)
     return n;
   
   return fibonaci(n-2)+fibonaci(n-1);  
}

int main(){

 int n;
 printf("Unesite neki ceo broj: \n");
 scanf("%d", &n);
 if(n<0)
   greska();
 printf("Faktorijel unetog broja je: %d.\n", faktorijel(n));  
 printf("\n---------------------------------------\n");
 printf("N-ti po redu Fibonacijev broj je: %d.\n", fibonaci(n));  
   

 return 0;
}
