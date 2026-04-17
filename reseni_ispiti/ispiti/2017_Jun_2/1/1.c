#include <stdio.h>
#include <stdlib.h>

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int jeste_savrsen(int x){

  int suma_delilaca = 0;
  for (int i = 1; i < x; i++){
    if (x % i == 0){
      suma_delilaca += i;
    }
  }
  if (suma_delilaca == x){
    return 1;
  }
  return 0;
}

int main(int argc, const char* argv[]){

  if (argc != 3){
    greska();
  }
    
  int a, b;
  a = atoi(argv[1]);
  b = atoi(argv[2]);

  if (a < 0 || a > b)
    greska();
    
  for (int i = a; i < b; i++){
    if (jeste_savrsen(i))
      printf("%d ", i);
  }
  putchar('\n');

  return 0;
}
