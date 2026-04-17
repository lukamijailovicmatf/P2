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

int broj_sekvenci(unsigned x, int k){

  if (k > (int)(8*sizeof(unsigned)))
    return 0;
    
  unsigned mask = 1 << (8*sizeof(unsigned) - 1);
  int i = k;
  while (i != 1){
    mask |= mask >> 1;   
    i--;
  }

  int ponavljanja = 0;
  int j = 8*sizeof(unsigned) - k + 1;
  while (j){
    if ((x & mask) == mask)
      ponavljanja++;
    mask >>= 1;
    j--;
  }
  return ponavljanja;
}

int main(){

  unsigned x;
  int k;
  scanf("%u%d", &x, &k);
  if (k <= 0)
    greska();
    
  printf("%d\n", broj_sekvenci(x, k));
    
  return 0;
}




