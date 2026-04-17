#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){

 if(argc!=2)
   greska();
 
 int zagrade=0;
 FILE *f=fopen(argv[1], "r");
 if(f==NULL)
   greska();
 char c; 
 while((c=fgetc(f))!=EOF){
    if(c=='('){
      zagrade++;
    } else if(c==')'){
      zagrade--;
      if(zagrade<0){
        printf("nisu");
        return -1;
      }
    } else {
      continue;
    }
 }  
 if(zagrade>0)
   printf("nisu");
 else 
   printf("jesu");  
   
 fclose(f);    

 return 0;
}
