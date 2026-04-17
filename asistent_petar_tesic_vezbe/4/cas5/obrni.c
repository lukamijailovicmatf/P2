#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

/*
Funkcija koja odredjuje broj cifara celog broja x
*/
int broj_cifara(int x){
   if(x<10)
     return 1;
   
   return 1+broj_cifara(x/10);  
}

/*
Funkcija koja obrce cifre broja x
*/
int obrni(int x, int p)
{
  if(x == 0)
    return 0;
  
  return (x%10)*pow(10, p) + obrni(x/10, p-1);
}


int main(){

 int n;
 int sign=1;
 printf("Unesite ceo broj n: \n");
 scanf("%d", &n);
 if(n<0){
   sign=-1;
   n=abs(n);
 }
 int duzina=broj_cifara(n);
 printf("Broj nakon obrtanja njegovih cifara izgleda ovako: %d.\n", sign*obrni(n, duzina-1));

 return 0;
}
