#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
 
  if(argc<3){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
  }
  
  int a=atoi(argv[1]);
  int b=atoi(argv[2]);
  
  if(a>=b){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
  }

  for(int i=a;i<=b;i++){
     printf("%d ", i);
  }
  printf("\n");

  return 0;
}
