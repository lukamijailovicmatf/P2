#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned invert_i(unsigned x, int i){

  if(i<0 || i>=32)
    return x;
      
  if(i==0)
    return x^1;
    
  unsigned mask=1;
  for(int j=0; j<32; j++){
    if(j%i==0)
      x^=mask; 
    mask<<=1;
  }
  return x;  
}

void print_bits(unsigned x){

  unsigned mask=1;
  mask<<=sizeof(unsigned)*8-1;
  for(int i=1;i<=32;i++){
    if((mask & x)!=0)
      printf("1");
    else
      printf("0");
    mask>>=1;    
  }
  printf("\n");
}

int main(){

    int i;
    unsigned x;

    scanf("%d", &i);
    scanf("%u", &x);

    //print_bits(x);
    x=invert_i(x, i);
    //printf("\n---------------------------------\n");
    //print_bits(x);
    printf("%u", x);

    return 0;
}