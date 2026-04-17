#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAZIV 21

void greska();

int main(int argc, char* argv[])
{
    // provera broja argumenata komandne linije
    if(argc != 5)
        greska();

    // smestanje odgovarajucih vrednosti u promenljive a, b, n, ime_dat
    int a, b, n;
    char ime_dat[MAX_NAZIV];
    FILE* fp;

    a = atoi(argv[1]);
    if(a < 0)
        greska();
    b = atoi(argv[2]);
    if(b < 0)
        greska();
    n = atoi(argv[3]);
    if(n <= 0)
        greska();
    sscanf(argv[4], "%s", ime_dat);

    // otvaranje datoteke
    fp = fopen(ime_dat, "r");
    if(NULL == fp)
        greska();

    // odredjivanje broja brojeva iz datoteke koji zadovoljavaju uslov zadatka (promen. rezultat)
    int i, rezultat = 0;
    float br, zbir_kvadrata = a*a + b*b;
    for(i = 0; i < n; i++) {
        fscanf(fp, "%f", &br);
        if(br > zbir_kvadrata)
            rezultat++;
    }

    // ispis rezultata u datoteku ispis.txt
    FILE* izlaz = fopen("izlaz.txt", "w");
    if(NULL == izlaz)
        greska();

    fprintf(izlaz, "%d\n", rezultat);

    // zatvaranje datoteka
    fclose(fp);
    fclose(izlaz);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}