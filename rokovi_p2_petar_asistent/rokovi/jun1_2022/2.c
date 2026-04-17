#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned k_jedinica(unsigned x, unsigned k){

 unsigned brojac=0;
 unsigned mask=~(~0<<k);

 for(int i=0; i<8*sizeof(unsigned)-k+1; i++){
    if((x & mask)==mask)
      brojac++;
    mask<<=1;  
 }
 return brojac;
}

int main(){

  unsigned x;
  unsigned k;
  scanf("%u %u", &x, &k);
  printf("%u\n", k_jedinica(x, k));

  return 0;
}