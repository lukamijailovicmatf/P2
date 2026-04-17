/*
Napisati program koji u datoteci ˇcije se ime zadaje kao argument komandne linije, pronalazi i na
standardni izlaz ispisuje sve linije u kojima se zadata reˇc pojavljuje n puta. Traˇzena rec i broj pojavljivanja
n se zadaju sa standardnog ulaza. Maksimalna duˇzina reˇci je 20 karaktera. U sluˇcaju greˇske, na standardni
izlaz za greˇske ispisati -1.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21 

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){

 if(argc!=2)
   greska();
  
 char rec[MAX];
 int n;
 printf("Unesite rec i njenu frekvenciju: \n");
 scanf("%s %d", rec, &n);
 
 FILE *f=fopen(argv[1], "r");
 if(f==NULL)
   greska();
 
 
 //----------------------------------- 
 char *linija=NULL;
 size_t duzina=0;  
 while(getline(&linija, &duzina, f)!=-1){
     char tmp[MAX];
     int procitano=0;
     int k=0;
     int freq=0;
     while(sscanf(linija+procitano, "%s%n", tmp, &k)!=EOF){
          procitano+=k;
          if(strcmp(rec, tmp)==0)
            freq++;
     }
     if(freq==n)
       printf("%s", linija); 
 }


 fclose(f);

 return 0;
}
