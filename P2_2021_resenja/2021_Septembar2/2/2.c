#include <stdio.h>
#include <stdlib.h>

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

unsigned invertovanje(unsigned x){

  unsigned mask_brojac = 1 << (8*sizeof(unsigned) - 3); /* 00100...00000 */
  unsigned mask_3_4 = 4;  /* 100  (treca pozicija) */

  while (mask_brojac){
    if (x & mask_3_4)
      x &= ~mask_3_4;
    else
      x |= mask_3_4;
    
    mask_3_4 <<= 1;
    mask_brojac >>= 1;

    if (x & mask_3_4)
      x &= ~mask_3_4;
    else
      x |= mask_3_4;

    mask_3_4 <<= 3;
    mask_brojac >>= 3;
  }
  return x;
}

int main(){

  unsigned x;
  scanf("%x", &x);

  printf("%x\n", invertovanje(x));    

  return 0;
}