#include <stdio.h>
#include <stdlib.h>

void greska();
int izmeniNiz(int* niz, int n);
void unesi_niz(int* a, int n);
void ispisi_niz(int* a, int n);

int main()
{
    int n;
    scanf("%d", &n);
    if(n < 0)
        greska();
    
    // alokacija memorije za niz
    int* niz = (int*)malloc(n * sizeof(int));
    if(NULL == niz)
        greska();

    unesi_niz(niz, n);
    izmeniNiz(niz, n);
    ispisi_niz(niz, n);
    // oslobadjanje alocirane memorije
    free(niz);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int izmeniNiz(int* niz, int n)
{
    if(n <= 1)
        return 1;
    
    int p;
    if((*niz % 2 == 1 && *(niz+n-1) % 2 == 0) || (*niz % 2 == 0 && *(niz+n-1) % 2 == 1)) {
        p = *niz;
        *niz = *(niz+n-1);
        *(niz+n-1) = p;
    }

    return izmeniNiz(niz+1, n-2);
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