#include <stdio.h>
#include <stdlib.h>

void greska();
int f3(int x);

int main()
{
    int x;
    scanf("%d", &x);
    printf("%d\n", f3(abs(x)));
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
        return 0;

    int rez = f3(x/10);

    if(x%10 < (x%100)/10)
        return rez + 1;
    return rez;
}