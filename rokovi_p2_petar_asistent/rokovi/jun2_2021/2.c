#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_bits(unsigned x){
    unsigned mask=1;
    mask<<=sizeof(unsigned)*8-1;
    for(int i=1;i<=sizeof(unsigned)*8;i++){
        if((mask & x)!=0)
          printf("1");
        else
          printf("0");
        mask>>=1;    
    }
    printf("\n");
}

unsigned izmeni(unsigned x){
    unsigned mask=1<<(sizeof(unsigned)*8-1);
    for(int i=1;i<=sizeof(unsigned)*8;i++){
        if(i%2==1)
          x^=mask;
        mask>>=1;  
    }
    return x;
}

int main(){
 
    unsigned x;
    scanf("%u", &x);
    printf("\n--------------------------------\n");
    printf("%u -> ", x);
    print_bits(x);
    x=izmeni(x);
    printf("\n--------------------------------\n");
    printf("%u -> ", x);
    print_bits(x);


    return 0;
}