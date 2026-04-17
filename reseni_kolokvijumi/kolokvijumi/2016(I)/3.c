#include <stdio.h>
#include <stdlib.h>

void greska();
int f3(int x);

int main()
{
    int x;
    scanf("%d", &x);
    
    int znak = (x < 0)? -1 : 1;
    printf("%d\n", znak * f3(abs(x)));

    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int f3(int x)
{
    if(x <= 9)
        return x;
    
    int novi_broj = f3(x/10);

    if(x % 2 && (x%100)/10 == 2)
        return novi_broj;
    
    return novi_broj*10 + x%10;
}