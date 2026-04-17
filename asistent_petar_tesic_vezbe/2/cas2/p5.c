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

#define MAX 51
#define MAX_LENGTH 256


int main(){

 char file[21];
 scanf("%s", file); 

 FILE *in=fopen(file, "r");
 if(in==NULL){
   fprintf(stderr,"-1\n");
   exit(EXIT_FAILURE);
 }
 
 FILE *out=fopen("rez.txt", "w");
 if(out==NULL){
   fprintf(stderr,"-1\n");
   exit(EXIT_FAILURE);
 }
 
 int n;
 fscanf(in, "%d", &n);
 char rec[MAX];
 char ispisano[MAX_LENGTH][MAX];
 int size=0;
 for(int i=0;i<n;i++){
    fscanf(in, "%s", rec);
    printf("%s ", rec);
    int flag=0;
    for(int j=0;j<size;j++){
       if(strcmp(ispisano[j], rec)==0){
         flag=1;
         break;
       }
    }
    if(!flag){
      fprintf(out, "%s ", rec);
      strcpy(ispisano[size++], rec);
      //size++;
    }
 }
 
 
 fclose(in);
 fclose(out);

 return 0;
}
