#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

typedef struct {
  char naslov[100];
  double ocena_gledalaca;
  unsigned broj_gledalaca;
  double ocena_kriticara;
}FILM;

int compare(const void *x, const void *y){

 FILM *film1=(FILM*)x;
 FILM *film2=(FILM*)y;
 int M=10000;

 double tmp1=(film1->ocena_gledalaca*film1->broj_gledalaca+M*film1->ocena_kriticara)/(M+1);
 double tmp2=(film2->ocena_gledalaca*film2->broj_gledalaca+M*film2->ocena_kriticara)/(M+1);

  if(strcmp(film1->naslov, film2->naslov)<0)
    return -1;
  else if(strcmp(film1->naslov, film2->naslov)>0)
    return 1;
  else{
    if(tmp1>tmp2)
      return -1;
    else 
      return 1;  
 }    
}

int main(int argc, char* argv[]){
    
  if(argc!=2)
    greska();

  FILE *in=fopen(argv[1], "r");
  if(in==NULL)
    greska();
    
  FILE *out=fopen("vrednosti.txt", "w");
  if(out==NULL)
    greska();

  int n;
  FILM *niz;
  int M=10000;
  fscanf(in, "%d", &n);

  niz=(FILM*)malloc(n*sizeof(FILM));
  if(niz==NULL)
    greska();
      
  for(int i=0; i<n; i++)
     fscanf(in, "%s %lf %u %lf", niz[i].naslov, &niz[i].ocena_gledalaca, &niz[i].broj_gledalaca, &niz[i].ocena_kriticara);

  qsort(niz, n, sizeof(FILM), compare);

  for(int i=0; i<n; i++)
     fprintf(out, "%s %.2lf\n", niz[i].naslov, (niz[i].ocena_gledalaca*niz[i].broj_gledalaca+M*niz[i].ocena_kriticara)/(M+1));

  free(niz);
  fclose(in);
  fclose(out);  

  return 0;
}