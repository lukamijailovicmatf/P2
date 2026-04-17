#include <stdio.h>
#include <stdlib.h>

void greska();
void f3(int* a, int na, int suma_prethodnih);
void unesi_niz(int* a, int n);
void ispisi_niz(int* a, int n);

int main()
{
    int n;
    scanf("%d", &n);
    if(n <= 0)
        greska();
    
    int* niz = (int*)malloc(n * sizeof(int));
    if(NULL == niz)
        greska();

    unesi_niz(niz, n);
    f3(niz, n, 0);
    ispisi_niz(niz, n);

    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void f3(int* a, int na, int suma_prethodnih)
{
    if(na == 0)
        return;
    
    if(*a > suma_prethodnih) {
        suma_prethodnih += *a;
        *a = 0;
    }
    else
        suma_prethodnih += *a;
    
    f3(a+1, na-1, suma_prethodnih);
}

void unesi_niz(int* a, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void ispisi_niz(int* a, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    putchar('\n');
}