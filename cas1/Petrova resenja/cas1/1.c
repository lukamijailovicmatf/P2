#include <stdio.h>
#include <stdlib.h>
#define MAX 100


int main(){
  
  FILE* in=fopen("ulaz.txt", "r");
  if(in==NULL){
    fprintf(stderr,"Greska!\n");
    exit(EXIT_FAILURE);
  }
  
  FILE *out=fopen("izlaz.txt", "w");
  
  if(out==NULL){
    fprintf(stderr,"Greska!\n");
    exit(EXIT_FAILURE);
  }
  char c;
  /*
  while((c=fgetc(in))!=EOF){
    fputc(c, out);
  }
  */
  char buffer[MAX];
  while(fgets(buffer, MAX, in)!=NULL){
      int x=fputs(buffer, out);
      if(x==EOF){
        fprintf(stderr,"Greska!\n");
        exit(EXIT_FAILURE);
      }
  }
  
  
  fclose(in);
  fclose(out);

  return 0;
}
