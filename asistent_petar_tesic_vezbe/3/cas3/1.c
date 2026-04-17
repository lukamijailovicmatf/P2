/*
Napisati program koji filtrira datoteku imena.txt tako sto na standardni izlaz ispisuje samo imena
i prezimena. Maksimalna duzina imena, kao i prezimena je 50 karaktera.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 51

void greska(){
 fprintf(stderr,"-1\n");
 exit(EXIT_FAILURE);

}

int main(){

 FILE *f=fopen("imena.txt", "r");
 if(f==NULL)
   greska();
 
 char ime[MAX];
 char prezime[MAX];
 //int redni;
 //float prosek;
 while(fscanf(f, "%*d. %s %s %*f", ime, prezime)==2){
   printf("%s %s\n", ime, prezime);
 }
 
 fclose(f);  

 return 0;
}
