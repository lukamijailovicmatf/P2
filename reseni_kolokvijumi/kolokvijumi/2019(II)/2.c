#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINIJA 201

void greska();
// f-ja koja vraca broj cifara u jednom stringu
int br_cifara(char* s);

int main(int argc, const char* argv[])
{
    // provera broja argumenata
    if(argc != 2)
        greska();
    
    // otvaranje datoteke
    FILE* f = fopen(argv[1], "r");
    if(NULL == f)
        greska();
    
    // ispis u trazenom formatu
    int redni_br_linije = 1;
    char linija[MAX_LINIJA];

    while(fgets(linija, MAX_LINIJA, f) != NULL) {
        printf("%d:%d\n", redni_br_linije, br_cifara(linija));
        redni_br_linije++;
    }

    // zatvaranje datoteke i izlazak iz programa
    fclose(f);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int br_cifara(char* s) 
{
    int br_cif = 0;
    
    for(int i = 0; s[i]; i++) {
        if(isdigit(s[i]))
            br_cif++;
    }

    return br_cif;
}