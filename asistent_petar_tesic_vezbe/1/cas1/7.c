#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
 
  printf("Broj argumeneta komandne linije iznosi: %d!\n", argc);
  for(int i=0;i<argc;i++){
     printf("%d. %s\n", i+1, argv[i]);
  }
  
  return 0;
}
