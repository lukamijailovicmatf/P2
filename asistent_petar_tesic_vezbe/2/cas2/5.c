/*
Sa standardnog ulaza se uˇcitava reˇc pretrage, dimenzija niza, a zatim i niz reˇci. Pretpostavljati
da je maksimalna duzina reˇci 20 karaktera (prostor za reˇc alocirati dinamiˇcki). Na standardni izlaz ispisati
indeks prvog i poslednjeg pojavljivanja traˇzene reˇci u okviru unetog niza reˇci. U sluˇcaju da se reˇc ne pojavljuje
u nizu, ispisati -1 za obe pozicije. U sluˇcaju greˇske na standardni izlaz za greˇske ispisati -1.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

int main(){

  char* rec=(char *)malloc(20*sizeof(char));
  if(rec==NULL)
    greska();
  
  int n;
  printf("Unesite rec za pretrazivanje: \n");
  scanf("%s", rec);
  printf("Unesite duzinu niza reci koje zelite da unesete:\n");
  scanf("%d", &n);
  
  char **reci=(char**)malloc(n*sizeof(char*));
  if(reci==NULL)
    greska();
  for(int i=0;i<n;i++){
     reci[i]=(char*)malloc(20*sizeof(char));
     if(reci[i]==NULL)
       greska();
  }  
  
  
  printf("Sada mozete uneti reci: \n");
  char* tmp=(char *)malloc(20*sizeof(char));
  if(tmp==NULL)
    greska();
  int max_index=-1;
  int min_index=-1;
  for(int i=0;i<n;i++){
     scanf("%s", reci[i]);
     if(strcmp(rec, reci[i])==0 && min_index==-1){
       min_index=i;
       max_index=i;
     } else if(strcmp(rec,reci[i])==0){
       max_index=i;
     }
  }

  printf("%d %d\n", min_index, max_index);

  for(int i=0;i<n;i++){
     free(reci[i]);
  }
  free(reci);
 

  return 0;
}
