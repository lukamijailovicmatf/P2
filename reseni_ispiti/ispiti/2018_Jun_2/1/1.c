#include <stdio.h>
#include <stdlib.h>

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int jeste_prost(int x){

  for (int i = 2; i < x; i++){
    if (x % i == 0)
      return 0;
  }
  return 1;
}

int main(int argc, const char* argv[]){

  if (argc != 3)
    greska();
    
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  if (a <= 0 || a > b)
    greska();

  for (int i = a; i <= b; i++){
    if (jeste_prost(i))
      printf("%d ", i);
  }
  putchar('\n');
    
  return 0;
}