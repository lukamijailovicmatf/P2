#include <stdio.h>
#include <stdlib.h>

void greska();
int podeliCifreSa3(int n);

int main()
{
    int n;
    scanf("%d", &n);
    if(n <= 0)
        greska();

    printf("%d\n", podeliCifreSa3(n));
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int podeliCifreSa3(int n)
{
    if(n == 0)
        return n;
    
    int novi_broj = podeliCifreSa3(n/10);
    if((n % 10) % 3 == 0)
        return novi_broj*10 + (n%10)/3;
    
    return novi_broj*10 + n%10;
}