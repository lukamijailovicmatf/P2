#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int main(int argc, char* argv[]){

  char file1[MAX];
  char file2[MAX];
  char c;
  scanf("%s %s %c", file1, file2, &c);
  printf("%s %s %c\n",file1, file2, c);
  FILE *in=fopen(file1, "r");
  if(in==NULL){
    fprintf(stderr,"FOPEN\n");
    exit(EXIT_FAILURE);
  }
  
  FILE *out=fopen(file2, "w");
  if(out==NULL){
    fprintf(stderr,"FOPEN\n");
    exit(EXIT_FAILURE);
  }
  
  if(c=='1'){
    char tmp;
    while((tmp=fgetc(in))!=EOF){
       if(tmp>='A' && tmp<='Z'){
         tmp='a'+(tmp-'A');
         fputc(tmp, out);
       } else if(tmp>='a' && tmp<='z'){
         fputc(tmp, out);
       } else if(tmp==' ' || tmp=='\n') {
         fputc(tmp, out);
       } else {
         fprintf(stderr,"Invalid character!\n");
         exit(EXIT_FAILURE);
       }
    } 
  } else if(c=='u'){
    char tmp;
    while((tmp=fgetc(in))!=EOF){   
       if(tmp>='A' && tmp<='Z'){
         fputc(tmp, out);
       } else if(tmp>='a' && tmp<='z'){
         tmp='A'+(tmp-'a');
         fputc(tmp, out);
       } else if(tmp==' ' || tmp=='\n') {
         fputc(tmp, out);
       } else {
         fprintf(stderr,"Invalid character!\n");
         exit(EXIT_FAILURE);
       }
    }   
  } else {
    fprintf(stderr,"Invalid option!\n");
    exit(EXIT_FAILURE);
  }
  

  return 0;
}
