#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned izmeni(unsigned x){
    unsigned mask=1<<(sizeof(unsigned)*8-1);
    for(int i=1;i<=sizeof(unsigned)*8;i++){
        if((i-1)%2==0)
          x^=mask;
        mask>>=1;   
    }
    return x;
}

int main(){

    unsigned x;
    scanf("%u", &x);
    x=izmeni(x);
    printf("%u\n", x);

    return 0;
}