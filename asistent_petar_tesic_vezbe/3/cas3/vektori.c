#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
  int x;
  int y;
  int z;
} VEKTOR;

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

int main(){

 FILE *f=fopen("vektori.txt", "r");
 if(f==NULL)
   greska();
 
 int x, y, z;
 int n;
 fscanf(f, "%d", &n);
 if(n<=0)
   greska();
 
 VEKTOR* niz=(VEKTOR*)malloc(n*sizeof(VEKTOR));
  if(niz==NULL)
    greska();
 // -------------------------  
 float max=-1;
 int max_index=-1;
 for(int i=0;i<n;i++){
    fscanf(f, "%d %d %d", &x, &y, &z);
    niz[i].x=x;
    niz[i].y=y;
    niz[i].z=z;
    if(sqrt(niz[i].x*niz[i].x+niz[i].y*niz[i].y+niz[i].z*niz[i].z)>max){
      max=sqrt(niz[i].x*niz[i].x+niz[i].y*niz[i].y+niz[i].z*niz[i].z);
      max_index=i;
    }
 }
 
 printf("%d %d %d\n", niz[max_index].x, niz[max_index].y, niz[max_index].z);
 
 free(niz);
 fclose(f);  

 return 0;
}
