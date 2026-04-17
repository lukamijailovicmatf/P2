#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KORAK 10
#define MAX 17

typedef struct _kartica
{
    char broj[MAX];
    float suma;
}Kartica;

void greska();
int vec_postoji(Kartica* niz, int n, Kartica tmp);
Kartica* formiraj_niz(FILE* f, int* n);

void ispisi(Kartica* niz, int n);

int uporedi_kartica(const void* a, const void* b);
int uporedi_suma(const void* a, const void* b);

int main(int argc, const char* argv[])
{
    if (argc != 4)
    {
        greska();
    }

    char* ime_dat = malloc((strlen(argv[1]) + strlen(argv[2]) + 5) * sizeof(char));
    // +5 za donju crtu i ".txt"
    if (NULL == ime_dat)
    {
        greska();
    }

    strcpy(ime_dat, argv[1]);
    strcat(ime_dat, "_");
    strcat(ime_dat, argv[2]);
    strcat(ime_dat, ".txt");
    
    FILE* f = fopen(ime_dat, "r");
    if (NULL == f)
    {
        free(ime_dat);
        greska();
    }
    
    int n;
    Kartica* niz = formiraj_niz(f, &n);
    
    // opcije
    if (strcmp(argv[3], "-kartica") == 0)
    {
        qsort(niz, n, sizeof(Kartica), &uporedi_kartica);
    }
    else if (strcmp(argv[3], "-suma") == 0)
    {
        qsort(niz, n, sizeof(Kartica), &uporedi_suma);
    }
    else
    {
        free(ime_dat);
        greska();
    }
    
    ispisi(niz, n);
    
    free(niz);
    free(ime_dat);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

Kartica* formiraj_niz(FILE* f, int* n)
{
    int alocirano = KORAK;
    Kartica* niz = malloc(alocirano * sizeof(Kartica));
    if (NULL == niz)
    {
        greska();
    }
    
    Kartica tmp;
    int i = 0;
    while (fscanf(f, "%s%f", tmp.broj, &tmp.suma) != EOF)
    {
        int index = vec_postoji(niz, i, tmp);
        if (index == -1)
        {
            strcpy(niz[i].broj, tmp.broj);
            niz[i].suma = tmp.suma;
            i++;
            if (i == alocirano)
            {
                alocirano += KORAK;
                niz = realloc(niz, alocirano * sizeof(Kartica));
                if (NULL == niz)
                {
                    greska();
                }
            }
        }
        else
        {
            niz[index].suma += tmp.suma;
        }
    }
    
    *n = i;
    return niz;
}

int vec_postoji(Kartica* niz, int n, Kartica tmp)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(niz[i].broj, tmp.broj) == 0)
        {
            return i;
        }
    }
    
    return -1;
}

void ispisi(Kartica* niz, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s %f\n", niz[i].broj, niz[i].suma);
    }
}

int uporedi_kartica(const void* a, const void* b)
{
    Kartica* x = (Kartica*)a;
    Kartica* y = (Kartica*)b;

    if (strcmp(x->broj, y->broj) > 0)
    {
        return 1;
    }
    else if (strcmp(x->broj, y->broj) < 0)
    {
        return -1;
    }

    return 0;   // radi forme
}

int uporedi_suma(const void* a, const void* b)
{   
    Kartica* x = (Kartica*)a;
    Kartica* y = (Kartica*)b;

    if (x->suma > y->suma)
    {
        return -1;
    }
    else if (x->suma < y->suma)
    {
        return 1;
    }
    
    return 0;   // radi forme
}