#include <stdio.h>
#include <stdlib.h>

void greska();
// f-je koje rade ono sto je predvidjeno opcijama
int s(int* niz, int n);
int p(int* niz, int n);

int main(int argc, const char* argv[])
{
    // provera broja argumenata
    if(argc != 3)
        greska();
    
    // provera ispravnosti opcija
    if(argv[1][0] != '-' || (argv[1][1] != 'p' && argv[1][1] != 's')) 
        greska();
    
    int n = atoi(argv[2]);
    if(n <= 0)
        greska(); 
        
    // alokacija memorije za n celih brojeva
    int* niz = (int*)malloc(n * sizeof(int));
    if(NULL == niz)
        greska();
    
    // ucitavanje elemenata niza
    int i;
    for(i = 0; i < n; i++) {
        scanf("%d", &niz[i]);
    }

    // otvaranje datoteke
    FILE* izlaz = fopen("izlaz.txt", "w");
    if(NULL == izlaz)
        greska();
    
    // rezultat
    if(argv[1][1] == 's')
        fprintf(izlaz, "%d\n", s(niz, n));
    else
        fprintf(izlaz, "%d\n", p(niz, n));

    // zatvaranje datoteke i izlazak iz programa
    fclose(izlaz);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int s(int* niz, int n)
{
    int i, suma = 0;
    for(i = 0; i < n; i++)
        suma += niz[i];
    
    return suma;
}
int p(int* niz, int n) 
{
    int i, proizvod = 1;
    for(i = 0; i < n; i++)
        proizvod *= niz[i];

    return proizvod;
}