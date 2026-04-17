#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DUZINA 51

void greska();
int jeste_sufiks(char* rec, char* sufiks);

int main()
{
    // otvaranje datoteke
    FILE* dat = fopen("dat.txt", "r");
    if(NULL == dat)
        greska();

    char s[MAX_DUZINA];
    int n;
    fscanf(dat, "%s%d", s, &n);
    if(n < 0)
        greska();
    
    char rec[MAX_DUZINA];
    int i;
    for(i = 0; i < n; i++) {
        fscanf(dat, "%s", rec);
        if(jeste_sufiks(rec, s))
            printf("%s ", rec);
    }
    printf("\n");
        
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int jeste_sufiks(char* rec, char* sufiks)
{
    int nr = strlen(rec), ns = strlen(sufiks);
    if(ns > nr)
        return 0;

    int i, j;
    for(i = nr - 1, j = ns - 1; j >= 0; i--, j--) {
        if(rec[i] != sufiks[j])
            return 0;
    }

    return 1;
}