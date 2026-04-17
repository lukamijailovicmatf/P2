#include <stdio.h>
#include <stdlib.h>

void greska();
int zbir(int x);

int main()
{
    int n;
    scanf("%x", &n);
    printf("%d\n", zbir(n));
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int zbir(int x) 
{
    if(x == 0)
        return x;
    
    int rez = zbir(x/16);

    return rez + x%16;
}