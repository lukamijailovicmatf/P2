#include <stdio.h>
#include <stdlib.h>

typedef struct{
   unsigned a;
   unsigned b;
   char ime[5];
} PRAVOUGAONIK;

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){

 if(argc!=2)
   greska();
 FILE *in=fopen(argv[1], "r");
 if(in==NULL)
   greska();
 
 PRAVOUGAONIK *niz=(PRAVOUGAONIK *)malloc(2*sizeof(PRAVOUGAONIK));
 if(niz==NULL)
   greska();
 
 int i=0; 
 int max=0;
 while(fscanf(in, "%d %d %s", &niz[i].a, &niz[i].b, niz[i].ime)!=EOF){
    if(niz[i].a==niz[i].b){
      printf("%s ", niz[i].ime);
    } else {
      if(niz[i].a*niz[i].b>max)
        max=niz[i].a*niz[i].b;
    }
 
 } 
 if(max!=0)   
   printf("\n%d \n", max);
 free(niz);  
 
 fclose(in);  

 return 0;
}
