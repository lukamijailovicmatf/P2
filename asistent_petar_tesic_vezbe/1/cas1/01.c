#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main(){

  FILE *in=fopen("soba325.txt", "r");
  FILE *out=fopen("soba648.txt", "w");
  if(in==NULL){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
  }
  if(out==NULL){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
  }
  //Prepisivanje sadrzaja fajla karakter po karakter!
  /*
  char c;
  while((c=fgetc(in))!=EOF){
     fputc(c, out);
  }
  */
  char line[MAX];
  while(fgets(line, MAX, in)!=NULL){
    fputs(line, out);
  }
 
  fclose(in);
  fclose(out);
  
  return 0;
}
