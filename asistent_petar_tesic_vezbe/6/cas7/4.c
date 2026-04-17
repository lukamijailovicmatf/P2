#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

typedef struct {
  char ime[MAX];
  char prezime[MAX];
  char smer;
  double prosek;
} STUDENT;

int binarna(STUDENT *niz, int l, int r, char *prezime){

   if(l>r)
     return -1;
   
   int s=l+(r-l)/2;
   if(strcmp(prezime, niz[s].prezime)==0)
     return s;
   else if(strcmp(prezime, niz[s].prezime)>0)
     return binarna(niz, s+1, r, prezime);
   else
     return binarna(niz, l, s-1, prezime);      
}

int poredi(const void *x, const void *y){
   char *prezime=(char*)x;
   STUDENT s=*(STUDENT*)y;
   
   return strcmp(prezime, s.prezime);
}


int main(){

  int n;
  STUDENT *niz;
  char prezime[MAX];
  FILE *f=fopen("studenti.txt", "r");
  if(f==NULL)
    greska();
  
  fscanf(f, "%d", &n);
  if(n<=0)
    greska();
    
  niz=(STUDENT*)malloc(n*sizeof(STUDENT));
  if(niz==NULL)
    greska();
   
  for(int i=0;i<n;i++)
     fscanf(f, "%s %s %c %lf", niz[i].ime, niz[i].prezime, &niz[i].smer, &niz[i].prosek);
   
  printf("\n------------------------------\n");
  printf("Unesite prezime za pretragu: \n");
  scanf("%s", prezime);
  
  printf("\n------------------------------\n");
  printf("Rezultat binarne pretrage: \n");
  int k=binarna(niz, 0, n-1, prezime);
  printf("%s %s %c %.2lf\n", niz[k].ime, niz[k].prezime, niz[k].smer, niz[k].prosek);
  
  STUDENT *p=bsearch(prezime, niz, n, sizeof(STUDENT), poredi);
  if(p==NULL)
    printf("-1\n");
  else
    printf("%s %s %c %.2lf\n", p->ime, p->prezime, p->smer, p->prosek);     
    
  
  free(niz);  
  fclose(f);  

  return 0;
}
