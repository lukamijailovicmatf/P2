#include <stdio.h>
#include <stdlib.h>

#define KORAK 10

void greska();
int* rotiraj(int* niz, int n, int k);
void ispisi(int* niz, int n);

int main(int argc, const char* argv[])
{
    // provera broja argumenata
    if(argc != 2)
        greska();
    
    int k = atoi(argv[1]);
    if(k < 0)
        greska();
    
    // alokacija memorije za niz celih brojeva
    int* niz = (int*)malloc(KORAK * sizeof(int));
    if(NULL == niz)
        greska();
    
    int i = 0, alocirano = KORAK;
    while(scanf("%d", &niz[i]) != EOF) {
        if(i == alocirano - 1) {
            alocirano += KORAK;
            niz = (int*)realloc(niz, alocirano * sizeof(int));
            if(NULL == niz)
                greska();
        }
        i++;
    }
    if(i < 1)
        greska();
    
    int* rotirani_niz = rotiraj(niz, i, k);

    ispisi(rotirani_niz, i);

    // oslobadjanje memorije i izlazak iz programa
    free(niz);
    free(rotirani_niz);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int* rotiraj(int* niz, int n, int k) 
{
    k %= n;
    int* novi_niz = (int*)malloc(n * sizeof(int));
    if(NULL == novi_niz)
        greska();
    
    int i, j;
    for(i = n - k, j = 0; j < n; i++, j++) {
        if(i == n)
            i = 0;
        novi_niz[j] = niz[i];
    }

    return novi_niz;
}

void ispisi(int* niz, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", niz[i]);

    putchar('\n');
}