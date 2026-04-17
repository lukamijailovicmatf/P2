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

unsigned promeni_izmedju_prve_i_poslednje_jedinice(unsigned x){

  unsigned mask_poslednji = 1 << (8*sizeof(unsigned) - 1);
  unsigned mask_prvi = 1;
    
  short pronadjen_prvi = 0;
  short pronadjen_poslednji = 0;

  /* treci uslov za slucaj da je x = 0 */
  while ((!pronadjen_prvi || !pronadjen_poslednji) && mask_poslednji){
    if (x & mask_poslednji)
      pronadjen_poslednji = 1;
        
    if (x & mask_prvi)
      pronadjen_prvi = 1;

    if (!pronadjen_prvi)
      mask_prvi <<= 1;
        
    if (!pronadjen_poslednji)
      mask_poslednji >>= 1;
  }

  while (mask_prvi != mask_poslednji){
    x |= mask_prvi;
    mask_prvi <<= 1;   
  }
  return x;
}

int main(){

  unsigned x;
  scanf("%u", &x);
    
  printf("%u\n", promeni_izmedju_prve_i_poslednje_jedinice(x));

  return 0;
}