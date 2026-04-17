#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 51

int main(){

  char prva_rec[MAX];
  char tmp[MAX];
  char file[21];
  scanf("%s", file);
  FILE *in=fopen(file, "r");
  FILE *out=fopen("rez.txt", "w");
  if(in==NULL){
    fprintf(stderr,"FOPEN!\n");
    exit(EXIT_FAILURE);
  }
  
  if(out==NULL){
    fprintf(stderr,"FOPEN!\n");
    exit(EXIT_FAILURE);
  }
  
  int n;
  fscanf(in, "%d", &n);
  printf("%d\n", n);
  
  for(int i=1;i<=n;i++){
     fscanf(in, "%s", tmp);
     if(i==1) {
       strcpy(prva_rec, tmp);
     } else {
       int flag1=0;
       int flag2=0;
       for(int j=0;j<strlen(tmp);j++){
          if(tmp[j]=='_')
            flag2=1;
          if(tmp[j]==prva_rec[0] && strncmp(tmp+j*sizeof(char), prva_rec, strlen(prva_rec))==0)
            flag1=1;
       }
       if(flag1 && flag2){
         fputs(tmp, out);
         fputc(' ', out);
       }  
     }  
     printf("%s ", tmp);   
  }
  printf("\n");
  fclose(in);
  fclose(out); 

  return 0;
}
