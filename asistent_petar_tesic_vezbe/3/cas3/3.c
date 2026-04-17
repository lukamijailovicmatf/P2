/*
Napisati program koji za uneto n, formira fajlove 1.txt, 2.txt, ..., n.txt i popunjava ih na sledeci
nacin:
U 1.txt smesta cele brojeve [0,n] sa korakom 1 (0,1,...,n)
U 2.txt smesta cele brojeve [0,n] sa korakom 2 (0,2,4,...)
...
U n.txt smesta cele brojeve [0,n] sa korakom n (0 i n)
Maksimalna duˇzina imena fajla je 50 karaktera. Vrednost promenljive n mora biti u opsegu [0,100]. U sluˇcaju
greˇske na standardni izlaz za greˇske ispisati -1.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 51 

void greska(){
 fprintf(stderr,"-1\n");
 exit(EXIT_FAILURE);
}

int main(){

 int n;
 printf("Unesite pozitivan ceo broj: \n");
 scanf("%d", &n);
 if(n<0 || n>100)
   greska();
 
 
 for(int i=1;i<=n;i++){
    char file[MAX];
    sprintf(file, "%d.txt", i);
    FILE *f=fopen(file, "w");
    if(f==NULL)
      greska();
      
    for(int j=0;j<=n;j+=i){
       fprintf(f, "%d ", j);
    }  
    fprintf(f, "\n"); 
      
    fclose(f);  
 }
 
 
 
 
 
 
 
 
 
 
   

 return 0;
}
