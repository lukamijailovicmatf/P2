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

int tri_uzastopne_jedinice(unsigned x){

  unsigned mask = 7 << (8*sizeof(unsigned) - 3);  /* 111 */

  while (mask != 3){
    if ((x & mask) == mask)
      return 1;
    mask >>= 1;
  }
  return 0;
}

int main(){

  unsigned a, b;
  scanf("%u%u", &a, &b);

  if (a > b)
    greska();
    
  for (unsigned i = a; i <= b; i++){

    if (tri_uzastopne_jedinice(i))
      printf("%u ", i);
  }
  putchar('\n');
    
  return 0;
}