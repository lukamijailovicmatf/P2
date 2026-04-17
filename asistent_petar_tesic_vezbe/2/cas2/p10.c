/*
Napisati program koji poredi dva fajla i ispisuje redni broj linija u kojima se fajlovi razlikuju.
Imena fajlova se zadaju kao argumenti komandne linije. Pretpostaviti da je maksimalna duzina reda u
datoteci 200 karaktera. Linije brojati pocevsi od 1. U slucaju greske na standardni izlaz za greske ispisati -1.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 201

int main(int argc, char *argv[]){

 if(argc!=3){
   fprintf(stderr,"-1");
   exit(EXIT_FAILURE);
 }
 
 FILE *file1=fopen(argv[1], "r");
 FILE *file2=fopen(argv[2], "r");
 if(file1==NULL || file2==NULL){
   fprintf(stderr,"-1");
   exit(EXIT_FAILURE);
 }
 
 char s1[MAX];
 char s2[MAX];
 int line=1;
 while(1){
   char *tmp1=fgets(s1, MAX, file1);
   char *tmp2=fgets(s2, MAX, file2);
   if(tmp1==NULL && tmp2==NULL)
     break;
   
   if(strcmp(s1, s2)!=0){
     printf("%d\n", line);
     //line++;
   }
   line++;  
 }
 
 
 fclose(file1);
 fclose(file2);


 return 0;
}
