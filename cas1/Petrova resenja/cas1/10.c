#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 201

int main(int argc, char* argv[]){
  
  if(argc!=3){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
  }
  FILE *f1=fopen(argv[1], "r");
  FILE *f2=fopen(argv[2], "r");
  if(f1==NULL){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
  }
  
  if(f2==NULL){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
  }
  
  char tmp1[MAX];
  char tmp2[MAX];
  char *flag1;
  char *flag2;
  int count_lines=1;
  while((flag1=fgets(tmp1, MAX, f1))!=NULL && (flag2=fgets(tmp2, MAX, f2))!=NULL){
      if(strcmp(tmp1, tmp2)!=0)
        printf("%d ", count_lines);
      count_lines++;  
  }
  if(flag1==NULL){
    flag2=fgets(tmp2, MAX, f2);
  }
  
  if(flag1!=NULL){
    printf("%d ", count_lines);
    count_lines++;
  }
  
  if(flag2!=NULL){
    printf("%d ", count_lines);
    count_lines++;
  }
    
  while(fgets(tmp1, MAX, f1)!=NULL){
     printf("%d ", count_lines);
     count_lines++;
  }
  
  while(fgets(tmp2, MAX, f2)!=NULL){
     printf("%d ", count_lines);
     count_lines++;
  }
  printf("\n");
  fclose(f1);
  fclose(f2);

  return 0;
}
