#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAXIV 51

// definisanje strukture za rad sa podacima o artiklima
typedef struct{
    char naziv[NAXIV];
    int kolicina;
}ARTIKAL;


void greska();

int main()
{
    int n;
    scanf("%d", &n);
    if(n < 0)
        greska();
    
    // alokacija memorije za niz artikala
    ARTIKAL* a = (ARTIKAL*)malloc(n * sizeof(ARTIKAL));
    if(NULL == a)
        greska();
    
    // unos niza
    int i, j, k, p;
    int tmp_kol;
    char tmp_naziv[NAXIV];

    for(i = 0, k = 0; i < n; i++) {
        scanf("%s%d", tmp_naziv, &tmp_kol);
        if(tmp_kol <= 0)
            greska();
        p = 1;
        for(j = 0; j < i; j++) {
            if(strcmp(tmp_naziv, a[j].naziv) == 0) {
                a[j].kolicina += tmp_kol;
                p = 0;
            }
        }
        if(p) {
            strcpy(a[k].naziv, tmp_naziv);
            a[k].kolicina = tmp_kol;
            k++;
        }
    }

    // realokacija memorije radi ustede
    a = (ARTIKAL*)realloc(a, k * sizeof(ARTIKAL));
    if(NULL == a)
        greska();
    
    // ispis 
    for(i = 0; i < k; i++)
        printf("%s %d\n", a[i].naziv, a[i].kolicina);

    // oslobadjanje alocirane memorije
    free(a);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}