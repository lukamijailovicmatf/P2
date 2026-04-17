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

unsigned rez(unsigned x, unsigned y){

  unsigned mask = 1 << (8*sizeof(unsigned) - 1);
  unsigned br_jedinica_x = 0;
  unsigned br_jedinica_y = 0;

  while (mask){

    if (x & mask)
      br_jedinica_x++;
    if (y & mask)
      br_jedinica_y++;
    mask >>= 1;
  }

  if (br_jedinica_x > br_jedinica_y)
    return ~x;
    
  mask = 1 << (8*sizeof(unsigned) - 1);
    
  unsigned rezultat = 0;
  while (mask){

    if ((x & mask) && !(y & mask))
      rezultat |= mask;
    mask >>= 1;
  }
  return rezultat;
}

int main(){

  unsigned a, b;
  scanf("%u %u", &a, &b);

  printf("%u\n", rez(a, b));

  return 0;
}