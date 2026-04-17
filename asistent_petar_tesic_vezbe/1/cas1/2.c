#include <stdio.h>
#include <stdlib.h>

#define MAX 100
 
int main(){
  
  FILE* in=fopen("knjige.txt", "r");
  if(in==NULL){
    fprintf(stderr,"Greska!\n");
    exit(EXIT_FAILURE);
  }
  
  //FILE* out=fopen("izlaz.txt", "w");
  char buffer[MAX];
  int count_lines=0;
  while(fgets(buffer, MAX, in)!=NULL){
     count_lines++;
  }
  printf("Ukupan broj linija u fajlu 'knjige.txt' iznosi: %d!\n", count_lines);

}
