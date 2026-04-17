#include <stdio.h>
#include <stdlib.h>

#define TEKUCA_GODINA 2022
#define DONJA_GRANICA_ZA_GODINE 1900    // pretpostavka
#define KORAK 10    // realokacija memorije

// definisanje strukture za rad sa podacima o kompanijama
typedef struct{
    int godina;
    float prihod;
    float rashod;
}KOMPANIJA;

void greska();
int binarna_pretraga(const void* niz, int n, int kljuc);

int main()
{
    // alokacija memorije za niz kompanija
    int alocirano = KORAK;
    KOMPANIJA* niz = (KOMPANIJA*)malloc(alocirano * sizeof(KOMPANIJA));
    if(NULL == niz)
        greska();
    
    // otvaranje datoteke sa podacima o kompanijama
    FILE* arhiva = fopen("arhiva.txt", "r");
    if(NULL == arhiva)
        greska();
    
    // ucitavanje elemenata niza iz datoteke
    int i = 0;
    while(fscanf(arhiva, "%d%f%f", &niz[i].godina, &niz[i].prihod, &niz[i].rashod) == 3) {
        // provera tacnosti podataka
        if(niz[i].godina > TEKUCA_GODINA || niz[i].godina < DONJA_GRANICA_ZA_GODINE)
            greska();
        
        if(niz[i].prihod < 0 || niz[i].rashod < 0)
            greska();
        
        i++;
        // realokacija memorije po potrebi
        if(i == alocirano) {
            alocirano += KORAK;
            niz = (KOMPANIJA*)realloc(niz, alocirano * sizeof(KOMPANIJA));
            if(NULL == niz)
                greska();
        }
    }

    // ucitavanje kljuca za pretragu
    int kljuc;
    scanf("%d", &kljuc);

    // smestanje povratne vrednosti f-je za sortiranje u promenljivu p
    int p = binarna_pretraga(niz, i, kljuc);
    if(p == -1)
        printf("Ne postoje informacije\n");
    else if(niz[p].prihod >= niz[p].rashod)
        printf("Zarada: %g\n", niz[p].prihod - niz[p].rashod);
    else
        printf("Gubitak: %g\n", -(niz[p].prihod - niz[p].rashod));

    // oslobadjanje memorije, zatvaranje datoteke i izlazak iz programa
    free(niz);
    fclose(arhiva);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int binarna_pretraga(const void* niz, int n, int kljuc)
{
    KOMPANIJA* p = (KOMPANIJA*)niz;
    int l = 0, d = n - 1;      // levi deo, desni deo
    int s = l + (d - l)/2;     // srednji clan

    while(l <= d) {
        if(p[s].godina == kljuc)
            return s;
        
        if(p[s].godina < kljuc)
            l = s + 1;
        else
            d = s - 1;
        
        s = l + (d - l)/2;
    }

    return -1;
}