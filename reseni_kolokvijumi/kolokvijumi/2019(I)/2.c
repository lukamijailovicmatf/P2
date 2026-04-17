#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINIJA 201

void greska();

int main(int argc, const char* argv[])
{
    // provera broja i ispravnosti argumenata
    if(argc != 3)
        greska();

    if(argv[2][0] != '-')
        greska();
    
    // otvaranje datoteke
    FILE* f = fopen(argv[1], "r");
    if(NULL == f)
        greska();

    // pretraga
    char linija[MAX_LINIJA];

    while(fgets(linija, MAX_LINIJA, f)) {
        if(strstr(linija, argv[2]+1)) {
            printf("%s", linija);
        }
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