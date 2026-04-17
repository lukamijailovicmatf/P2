/*
Zadatak 13: Napisati rekurzivnu funkciju int f3(int x) koja u poˇcetnom zapisu broja
x izbacuje svaku neparnu cifru, ukoliko se ispred te cifre nalazi cifra 2. Napisati program koji testira ovu
funkciju, tako ˇsto sa standardnog ulaza uˇcitava ceo broj x, i na standardni izlaz ispisuje vrednost funkcije
f3(x). U sluˇcaju greˇske ispisati -1 na standardni izlaz za greˇske.
Napomena: Zadatak mora biti uradjen rekurzivno. Nije dozvoljeno koriˇs ́cenje statiˇckih i globalnih promenljivih,
menjanje zaglavlja funkcije i pisanje pomo ́cnih funkcija.
*/
#include <stdio.h>
#include <stdlib.h>

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

int f3(int x){
   if(x<100){
     if(x/10==2 && x%2==1)
       return x/10;
     else
       return x;  
   }
   
   int tmp=f3(x/100);
   
   if(x%100/10==2 && x%2==1)
     return tmp*10+2;
   else
     return tmp*100+x%100;  
}

int main(){

  int x;
  printf("Unesite neki ceo broj x: \n");
  scanf("%d", &x);
  int sign=1;
  if(x<0){
    sign=-1;
    x=abs(x);
  }
  
  printf("Broj nakon izmene izgleda ovako: %d.\n", sign*f3(x));


  return 0;
}
