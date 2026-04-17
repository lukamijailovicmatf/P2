#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char puno_ime[101];
  int ocene[10];
  int broj_ocena;
  float prosek;
} STUDENT;

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

int najveci_prosek(STUDENT* niz, int n){
   return 1;
}

void ispisi(const STUDENT* s){
   printf("%s %.2lf\n", s->puno_ime, s->prosek);
}

int main(int argc, char *argv[]){
 
 if(argc!=2)
   greska();
  
 FILE *in=fopen(argv[1], "r");
 if(in==NULL)
   greska();
   
 int n;
 fscanf(in, "%d", &n);
 STUDENT *niz=(STUDENT *)malloc(n*sizeof(STUDENT));
 if(niz==NULL)
   greska();
 
 for(int i=0;i<n;i++){
    char ime[51];
    char prezime[51];
    fscanf(in, "%s %s", ime, prezime);
    strcpy(niz[i].puno_ime, ime);
    int k=strlen(ime);
    
    niz[i].puno_ime[k]=' ';
    k++;
    int j;
    for(j=0;j<strlen(prezime);j++)
       niz[i].puno_ime[k+j]=prezime[j];
    niz[i].puno_ime[k+j]='\0';
    int x;
    j=0;
    niz[i].broj_ocena=0;
    int sum=0;
    while(1){
       fscanf(in, "%d", &x);
       if(x==0)
         break;
       niz[i].ocene[j]=x;
       sum+=x;
       niz[i].broj_ocena++;
       j++;  
    }
    niz[i].prosek=(float)sum/niz[i].broj_ocena;   
 }  
   
 for(int i=0;i<n;i++){
    ispisi(&niz[i]);
 } 
 
 free(niz); 
   
   
 fclose(in);    

 return 0;
}
