#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101

void greska();
int ucitaj_liniju(char linija[], FILE* f);

int main(int argc, const char* argv[])
{
    // provera broja argumenata
    if(argc != 3)
        greska();
    
    // otvaranje datoteke
    FILE* fp = fopen(argv[1], "r");
    if(NULL == fp)
        greska();

    char linija[MAX];
    char* adresa;
    int redni_br_linije = 1, p = 1; // p - proverava da li je nesto ispisano
    
    while(ucitaj_liniju(linija, fp) != EOF) {
        adresa = strstr(linija, argv[2]);
        if(adresa != NULL) {
            printf("%d %ld\n", redni_br_linije, adresa - linija);
            p = 0;
        }
        
        redni_br_linije++;
    }
    
    if(p)
        puts("0");

    // zatvaranje datoteke
    fclose(fp);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int ucitaj_liniju(char linija[], FILE* f)
{
    int i = 0;
    char c;
    while((c = fgetc(f)) != EOF && c != '\n' && i < MAX) {
        linija[i] = c;
        i++;
    }
    linija[i] = '\0';

    if(c == EOF && i == 0)
        return EOF;

    return 1;
}