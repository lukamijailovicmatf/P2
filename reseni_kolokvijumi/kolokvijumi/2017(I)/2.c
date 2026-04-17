#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAJMANJA_OCENA 6
#define NAJVECA_OCENA 10
#define INDEX 8

// definisanje strukture za rad sa informacijama o studentima
struct Student{
    char indeks[INDEX];
    int zbir_ocena;
    int broj_ocena;
};

void greska();

int main()
{
    int n;
    scanf("%d", &n);   
    struct Student* s;
    s = (struct Student*)malloc(n * sizeof(struct Student));
    if(NULL == s)
        greska();

    // ucitavanje niza studenata
    int i, j, k, p;
    int tmp_ocena;
    char tmp_indeks[INDEX];
    for(i = 0, k = 0; i < n; i++) {
        scanf("%s%d", tmp_indeks, &tmp_ocena);
        if(tmp_ocena < NAJMANJA_OCENA || tmp_ocena > NAJVECA_OCENA)
            greska();
        p = 1;
        for(j = 0; j < i; j++) {
            if(strcmp(s[j].indeks, tmp_indeks) == 0) {
                s[j].zbir_ocena += tmp_ocena;
                s[j].broj_ocena++;
                p = 0;
            }
        }
        if(p) {
            strcpy(s[k].indeks, tmp_indeks);
            s[k].broj_ocena = 1;
            s[k].zbir_ocena = tmp_ocena;
            k++;
        }
    }

    // ispis
    for(i = 0; i < k; i++) {
        printf("%s %.2f\n", s[i].indeks, (float)s[i].zbir_ocena / s[i].broj_ocena);
    }
    // oslobadjanje memorije
    free(s);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}