#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

int compare(const void *x, const void *y){
    return *((int*)x)-*((int*)y);
}

int main(int argc, char* argv[]){
   
    if(argc!=3)
      greska();

    FILE* in=fopen(argv[1], "r");
    int x=atoi(argv[2]);
    if(in==NULL)
      greska();
 
    int n;
    int *niz;
    
    fscanf(in, "%d", &n);
    niz=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        fscanf(in, "%d", &niz[i]);
    }   

    qsort(niz, n, sizeof(int), compare);
    int l=0;
    int r=n-1;
    int s;
    while(l<=r){
        s=(l+r)/2;
        if(niz[s]==x)
          break;
        if(niz[s]<=x && s+1<n && niz[s]>x)
          break;
        if(niz[s]>x && s-1>=0 && niz[s-1]<=x){
            s=s-1;
            break;
        }
        
        if(niz[s]>x)
          r=s-1;
        else
          l=s+1;      
    }

    for(int i=0;i<=s/2;i++){
        int tmp=niz[s-i];
        niz[s-i]=niz[i];
        niz[i]=tmp;
    }

    for(int i=0;i<n;i++){
        printf("%d ", niz[i]);
    }
    printf("\n");


    free(niz);
    fclose(in);     


    return 0;
}