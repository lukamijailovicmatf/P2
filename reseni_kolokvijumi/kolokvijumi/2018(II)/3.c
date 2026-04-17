#include <stdio.h>
#include <stdlib.h>

#define KORAK 10  // za realokaciju memorije
#define MAX 51

// definisanje strukture za rad sa rad sa podacima o studentima
typedef struct{
    char ime[MAX];
    char prezime[MAX];
    float broj_poena;
}STUDENT;

void greska();
int binarna_pretraga(const void* niz, int n, float kljuc);

int main()
{
    // alokacija memorije za niz studenata
    int alocirano = KORAK;
    STUDENT* niz = (STUDENT*)malloc(alocirano * sizeof(STUDENT));
    if(NULL == niz)
        greska();

    // otvaranje datoteke koja sadrzi informacije o studentima
    FILE* dat = fopen("rezultati.txt", "r");
    if(NULL == dat)
        greska();

    // ucitavanje niza
    int i = 0;
    while(fscanf(dat, "%s%s%f", niz[i].ime, niz[i].prezime, &niz[i].broj_poena) == 3) {
        if(niz[i].broj_poena < 0)
            greska();
        
        i++;
        // realokacija po potrebi
        if(i == alocirano) {
            alocirano += KORAK;
            niz = (STUDENT*)realloc(niz, alocirano * sizeof(STUDENT));
            if(NULL == niz)
                greska();
        }
    }

    // ucitavanje kljuca za pretragu
    float x;
    scanf("%f", &x);
    if(x < 0)
        greska();
    
    // smestanje povratne vrednosti f-je za sortiranje u promenljivu p
    int p = binarna_pretraga(niz, i, x);
    if(p == -1)
        printf("Niko nije ostvario zadati broj poena\n");
    else
        printf("%s %s\n", niz[p].ime, niz[p].prezime);

    // oslobadjanje memorije, zatvaranje datoteke i izlazak iz programa
    free(niz);
    fclose(dat);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int binarna_pretraga(const void* niz, int n, float kljuc)
{
    STUDENT* p = (STUDENT*)niz;
    int l = 0, d = n - 1;      // levi deo, desni deo
    int s = l + (d - l)/2;     // srednji clan

    while(l <= d) {
        if(p[s].broj_poena == kljuc)
            return s;
        
        if(p[s].broj_poena < kljuc)
            l = s + 1;
        else
            d = s - 1;
        
        s = l + (d - l)/2;
    }

    return -1;
}