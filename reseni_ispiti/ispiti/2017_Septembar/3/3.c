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

short ponavljanja(unsigned n, unsigned m){

  unsigned mask_prva_4 = 15;     
  mask_prva_4 &= m;
  unsigned mask = 15; /* 1111 */

  /* print_bits(n);
  print_bits(m);
  print_bits(mask);
  print_bits(mask_prva_4); */
    
  short br = 0;
  unsigned mask_brojac = 1 << (8*sizeof(unsigned) - 4);

  while (mask_brojac){
    
    if ((n & mask) == mask_prva_4)
      br++;
        
    mask <<= 1;
    mask_prva_4 <<= 1;
    mask_brojac >>= 1;
  }
  return br;
}

int main(){

  unsigned n, m;
  scanf("%u %u", &n, &m);

  printf("%d\n", ponavljanja(n, m));
  return 0;
}