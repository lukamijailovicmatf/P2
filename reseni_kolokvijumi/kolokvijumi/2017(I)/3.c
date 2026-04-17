#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void greska();
int noviBroj(int x, int n);

int main()
{
    int x, n;
    scanf("%d%d", &x, &n);
    if(n < 0)
        greska();
    
    if(n && x / (int)pow(10, n-1) == 0) {
        puts("-1");
        return 0;
    }

    printf("%d\n", noviBroj(x, n));
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int noviBroj(int x, int n)
{
    if(x == 0)
        return x;
    
    if(x % 2 == 0 && n)
        return noviBroj(x/10, n-1);
    
    return noviBroj(x/10, n) * 10 + x%10;
}