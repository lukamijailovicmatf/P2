#include <stdio.h>
#include <stdlib.h>

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

void print_bits(unsigned x){

  unsigned mask = 1 << (8*sizeof(unsigned) - 1);

  while (mask){

    if (x & mask)
      putchar('1');
    else
      putchar('0');
    mask >>= 1;
  }
  putchar('\n');
}

unsigned izmeni(unsigned x){

  unsigned mask1 = 2;         /* 010 */
  unsigned mask2 = 5;         /* 101 */
  unsigned mask = 7;          /* 111 */
  unsigned mask_ = 1 << (8*sizeof(unsigned) - 1);  /* 1000...000 - za poredjenje u while petlji */

  while (mask1 != mask_){

    if ((x & mask) == mask1){
      x &= (~mask1);
    }else if ((x & mask) == mask2){
      x |= mask1;
    }
        
    mask1 <<= 1;
    mask2 <<= 1;
    mask <<= 1;
  }
  return x;
}

int main(){

  unsigned x;
  scanf("%u", &x);

  printf("%u\n", izmeni(x));

  return 0;
}