#include <stdio.h>
#include <stdlib.h>
#define MAX 51

void greska();

int main()
{
    // otvaranje datoteka
    FILE* ulaz1, *ulaz2, *izlaz;
    ulaz1 = fopen("u1.txt", "r");
    if(NULL == ulaz1)
        greska();
    
    ulaz2 = fopen("u2.txt", "r");
    if(NULL == ulaz2)
        greska();

    izlaz = fopen("i.txt", "w");
    if(NULL == izlaz)
        greska();

    int n1, n2;
    fscanf(ulaz1, "%d", &n1);
    if(n1 < 0)
        greska();
    
    fscanf(ulaz2, "%d", &n2);
    if(n2 < 0)
        greska();

    int i;
    char** niz1;
    char** niz2;

    // alokacija memorije za niz reci iz prve i druge ulazne datoteke
    niz1 = (char**)malloc(n1 * sizeof(char*));
    if(NULL == niz1)
        greska();
    for(i = 0; i < n1; i++) {
        niz1[i] = (char*)malloc(MAX * sizeof(char));
        if(NULL == niz1[i])
            greska();
    }

    niz2 = (char**)malloc(n2 * sizeof(char*));
    if(NULL == niz2)
        greska();
    for(i = 0; i < n2; i++) {
        niz2[i] = (char*)malloc(MAX * sizeof(char));
        if(NULL == niz2[i])
            greska();
    }

    // ucitavanje reci iz prve i druge ulazne datoteke
    for(i = 0; i < n1; i++) {
        fscanf(ulaz1, "%s", niz1[i]);
    }

    for(i = 0; i < n2; i++) {
        fscanf(ulaz2, "%s", niz2[i]);
    }

    int n = (n1 > n2)? n1 : n2;
    for(i = 0; i < n; i++) {
        if(i < n1)
            fprintf(izlaz, "%s ", niz1[i]);
        if(i < n2)
            fprintf(izlaz, "%s ", niz2[i]);
    }

    // zatvaranje datoteka i oslobadjanje memorije
    fclose(ulaz1);
    fclose(ulaz2);
    fclose(izlaz);
    free(niz1);
    free(niz2);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}