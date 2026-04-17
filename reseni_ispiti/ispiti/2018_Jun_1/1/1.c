#include <stdio.h>
#include <stdlib.h>


void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int broj_delilaca(int x){

  int br = 0;    
  for (int i = 1; i <= x; i++){
    if (x % i == 0)
      br++;
  }
  return br;
}

int main(int argc, const char* argv[]){

  if (argc != 3)
    greska();

  int a, b;
  a = atoi(argv[1]);
  b = atoi(argv[2]);

  if (a <= 0 || a > b)
    greska();
    
  int max_delilaca = 0;
  int rez, br_delilaca;
  for (int i = a; i <= b; i++){
    br_delilaca = broj_delilaca(i);
    if (max_delilaca < br_delilaca){
      max_delilaca = br_delilaca;
      rez = i;
    }
  }
  printf("%d %d\n", rez, max_delilaca);
  
  return 0;
}