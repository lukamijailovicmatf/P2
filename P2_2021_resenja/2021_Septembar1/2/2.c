#include <stdio.h>
#include <stdlib.h>

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

unsigned invertuj_svaku_drugu(unsigned x){

  unsigned mask = 1 << (8*sizeof(unsigned) - 1);

  while(mask){
    if (x & mask)
      x &= ~mask;
    else
      x |= mask;
    mask >>= 2;   
  }
  return x;
}

int main(){

  unsigned x;
  scanf("%u", &x);

  printf("%u\n", invertuj_svaku_drugu(x));

  return 0;
}