#include <stdio.h>
#include <stdlib.h>

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

unsigned invertuj(unsigned x){

  unsigned mask = 1 << (8*sizeof(unsigned) - 1);

  while (mask){
    if ((x & mask) == 0)
      x |= mask;
    mask >>= 2;
  }
  return x;
}

int main(){

  unsigned x;
  scanf("%u", &x);

  unsigned rez = invertuj(x);

  printf("%u\n", rez);
  return 0;
}