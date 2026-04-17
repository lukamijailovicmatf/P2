#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

typedef struct{
    char ime[51];
    int postanski_broj;
} GRAD;

int main(int argc, char *argv[]){

    if(argc!=3)
      greska();

    FILE *f=fopen(argv[1], "r");
    if(f==NULL)
      greska();
    
    int n=atoi(argv[2]);
    GRAD *niz=(GRAD *)malloc(n*sizeof(GRAD));
    int broj;
    if(niz==NULL)
      greska();

    for(int i=0;i<n;i++){
       fscanf(f, "%s %d", niz[i].ime, &niz[i].postanski_broj);
    }

    printf("Unesite postanski broj za pretragu: \n");
    scanf("%d", &broj);
    int l=0;
    int r=n-1;
    int s;
    int flag=0;
    while(l<=r){
        s=(l+r)/2;
        if(niz[s].postanski_broj==broj){
          flag=1;
          break;
        } else if(niz[s].postanski_broj<broj){
            l=s+1;
        } else {
            r=s-1;
        }
    }

    if(flag){
        printf("%s\n", niz[s].ime);
    }

    free(niz);
    fclose(f);    

    return 0;
}