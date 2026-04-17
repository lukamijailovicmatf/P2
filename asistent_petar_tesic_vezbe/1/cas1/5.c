/*
U datoteci cije se ime navodi na standarnom ulazu programa nalazi se broj n, a zatim i n reci
(duzine najvise 50 karaktera). Napisati program koji ucitava ovaj niz i
1. ispisuje ga na standardni izlaz,
2. iz njega uklanja sve duplikate i u datoteku rez.txt ispisuje transformisani niz
U slucaju greske na standardni izlaz za greske ispisati -1. Maksimalna duzina naziva datoteka je 20 karaktera.
Maksimalan broj reci je 256.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21
#define MAX_RECI 51

int main(int argc, char *argv[]){
 
 /*
 if(argc!2){
   fpritnf(stderr,"-1\n");
   exit(EXIT_FAILURE);
 }
 */
 char file[MAX];
 printf("Unesite ime datoteke koju zelite da otvorimo: \n");
 scanf("%s", file);
 
 FILE *in=fopen(file, "r");
 if(in==NULL){
   fprintf(stderr,"-1\n");
   exit(EXIT_FAILURE);
 }
 
 FILE *out=fopen("izlaz5.txt", "w");
 if(out==NULL){
   fprintf(stderr,"-1\n");
   exit(EXIT_FAILURE);
 }
 
 int n;
 fscanf(in, "%d", &n);
 if(n>256 || n<0){
   fprintf(stderr,"-1\n");
   exit(EXIT_FAILURE);
 }
 
 char rec[MAX_RECI];
 char printed[n][MAX_RECI];
 int k=0;
 for(int i=0;i<n;i++){
      fscanf(in, "%s", rec);
      printf("%s ", rec);
      
      int found=0;
      for(int j=0;j<k;j++){
         if(strcmp(printed[j], rec)==0){
           found=1;
           break;
         }  
      }
      
      if(!found){
        strcpy(printed[k], rec);
        fprintf(out, "%s ", rec);
        k++;
      }  
 }
 
 printf("\n");
 
 fclose(in);

 return 0;
}
