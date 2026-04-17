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

unsigned prva_i_poslednja_4(unsigned x){

  unsigned mask = 1;
  x |= mask;
  mask <<= 1;

  if (x & mask){
    x ^= mask;
  }
  mask <<= 1;

  if (x & mask){
    x ^= mask;
  }
  mask <<= 1;
  x |= mask;
    
  mask = 1 << (8*sizeof(unsigned) - 1);
  for (int i = 0; i < 4; i++){
    x ^= mask;
    mask >>= 1;
  }
  return x;
}

int main(){

  unsigned x;
  scanf("%u", &x);    
    
  unsigned rez = prva_i_poslednja_4(x);
    
  printf("%u\n", rez);
  return 0;
}

