#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 51

void greska();
int jeste_dekadni(char* r);

int main()
{   
    // otvaranje datoteka
    FILE* ulazna, *izlazna_b, *izlazna_o;
        // otvaranje i provera ulazne datoteke
    ulazna = fopen("r.txt", "r");
    if(NULL == ulazna)
        greska();

        // otvaranje i provera ispravnosti izlaznih datoteka
    izlazna_b = fopen("b.txt", "w");
    if(NULL == izlazna_b)    
        greska();
    
    izlazna_o = fopen("o.txt", "w");
    if(NULL == izlazna_o)
        greska();

    // ucitavanje broja reci iz datoteke r.txt
    int n;
    fscanf(ulazna, "%d", &n);
    if(n <= 0)
        greska();

    // ucitavanje i razvrstavanje reci iz r.txt
    char rec[MAX];
    int i;
    for(i = 0; i < n; i++) {
        fscanf(ulazna, "%s", rec);
        if(jeste_dekadni(rec))
            fprintf(izlazna_b, "%s ", rec);
        else    
            fprintf(izlazna_o, "%s ", rec);
    }
    
    // zatvaranje datoteka
    fclose(ulazna);
    fclose(izlazna_b);
    fclose(izlazna_o);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int jeste_dekadni(char* r)
{
    int i;
    for(i = 0; r[i]; i++) {
        if(!isdigit(r[i]))
            return 0;
    }

    return 1;
}