#include <stdio.h>
#include <stdlib.h>

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

unsigned ukloni(unsigned x, unsigned k){

  unsigned mask = 1 << (8*sizeof(unsigned) - 1);
  while (mask && k){
    if (x & mask){
      x &= ~mask;
      k--;
    } 
    mask >>= 1;
  }
  return x;
}

int main(int argc, const char *argv[]){

  if (argc != 3)
    greska();
    
  unsigned x = atoi(argv[1]);
  unsigned k = atoi(argv[2]);

  printf("%u\n", ukloni(x, k));
  return 0;
}



