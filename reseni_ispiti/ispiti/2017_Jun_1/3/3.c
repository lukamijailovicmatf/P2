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
    else{
      putchar('0');
    
    mask >>= 1;
  }
   putchar('\n');
}

unsigned svaki_treci(unsigned x){

  unsigned shift = 8*sizeof(unsigned) - 1 - (8*sizeof(unsigned))%3; 
  unsigned mask = 1 << shift;

  while (mask){

    x |= mask;
    mask >>= 3;   
  }
  return x;
}

int main(){

  unsigned x;
  scanf("%u", &x);
    
  print_bits(x);
  x = svaki_treci(x);
  print_bits(x);

  printf("%u\n", x);

  return 0;
}