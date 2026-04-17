#include <stdio.h>
#include <stdlib.h>

void greska();
int ukloniParneCifreNeparneUmanji(int n);

int main()
{
    int n;
    scanf("%d", &n);
    if(n <= 0)
        greska();
    
    printf("%d\n", ukloniParneCifreNeparneUmanji(n));
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int ukloniParneCifreNeparneUmanji(int n)
{
    if(n == 0)
        return n;
    
    int novi_broj = ukloniParneCifreNeparneUmanji(n/10);
    if(n % 2)
        return novi_broj*10 + n%10 - 1;
    return novi_broj;
}