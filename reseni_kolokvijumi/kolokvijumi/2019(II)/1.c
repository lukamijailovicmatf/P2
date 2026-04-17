#include <stdio.h>
#include <stdlib.h>

void greska();

int main(int argc, const char* argv[])
{
    // provera broja i tacnosti argumenata
    if(argc != 3)
        greska();
    
    int n = atoi(argv[1]);
    if(n < 1)
        greska();
    
    int k = atoi(argv[2]);
    if(k < 1)
        greska();
    
    // alokacija memorije i ucitavanje niza celih brojeva
    int* niz;
    niz = (int*)malloc(n * sizeof(int));
    if(NULL == niz)
        greska();

    int i;
    for(i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    // ispis k nasumicnih brojeva iz niza
    int nasumican_index;
    srand(5);
    for(i = 0; i < k; i++) {
        nasumican_index = rand() % n;
        printf("%d ", niz[nasumican_index]);
    }
    putchar('\n');
    
    // oslobadjanje memorije i izlazak iz programa
    free(niz);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}