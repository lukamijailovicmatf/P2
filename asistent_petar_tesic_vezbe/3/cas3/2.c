/*
Programu se kroz argumente komandne linije zadaje proizvoljan broj razlomaka u formatu a/b.
Na standardni izlaz ispisati vrednosti ovih razlomaka zapisane na dve decimale. U sluˇcaju greˇske na stan-
dardni izlaz za greˇske ispisati -1.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

int provera(const char *s){
   int crte=0;
   for(int i=0;s[i];i++){
      if(!isdigit(s[i]) && s[i]!='/')
        return 0;
      if(s[i]=='/')
        crte++;  
   }
   
   if(s[0]=='/' || s[strlen(s)-1]=='/' || crte!=1)
     return 0;
     
   return 1;
}

int main(int argc, char *argv[]){

 for(int i=1;i<argc;i++){
    if(provera(argv[i])==0)
      greska(); 
 } 
 
 // -----------------
 for(int i=1;i<argc;i++){
    int a;
    int b;
    sscanf(argv[i], "%d/%d", &a, &b);
    if(b==0)
      greska();
    printf("%.2f ", (float)a/b);
 }
 printf("\n");






 return 0;
}
