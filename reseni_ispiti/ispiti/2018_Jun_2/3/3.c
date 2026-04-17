#include <stdio.h>
#include <stdlib.h>

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}


void print_bits(unsigned x){

  unsigned mask = 1 << (8*sizeof(unsigned) - 1);

  int i = 1;
  while (mask){
    if (x & mask)
      putchar('1');
    else
      putchar('0');
    if (i % 8 == 0){
      putchar(' ');
    }
    i++;
    mask >>= 1;
  }
    putchar('\n');

unsigned razmenjeni_bajtovi(unsigned x, int i, int j){

  unsigned mask = 1 << (8*(i-1));

  for (int k = 1; k < 8; k++)
    mask ^= (mask << 1);
    
  unsigned mask_i = x & mask;
  x &= ~mask;

  mask = 1 << (8*(j-1));

  for (int k = 1; k < 8; k++)
    mask ^= (mask << 1);   
  
    
  unsigned mask_j = x & mask;
  x &= ~mask;

  if (i < j){
    mask_i <<= 8*(j-i);
    mask_j >>= 8*(j-i);
  }else{
    mask_i >>= 8*(i-j);
    mask_j <<= 8*(i-j);
  }    
  x |= mask_i;
  x |= mask_j;

  return x;
}

int main(int argc, const char* argv[]){

  if (argc != 3)
    greska();
    
  int i = atoi(argv[1]);
  int j = atoi(argv[2]);

  if (i <= 0 || j <= 0 || i > 4 || j > 4)
    greska();
    
  unsigned x;
  scanf("%u", &x);

  printf("%u\n", razmenjeni_bajtovi(x, i, j));

  return 0;
}

