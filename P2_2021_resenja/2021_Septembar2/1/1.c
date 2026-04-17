#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21

typedef struct {
  char ime[MAX];
  char boja[MAX];
  unsigned povrsina;    
}Figura;

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

void ucitaj_figure(Figura *niz, int n, FILE *f){
  for (int i = 0; i < n; i++)
    fscanf(f, "%s %s %u", niz[i].ime, niz[i].boja, &niz[i].povrsina);
}

void ispisi_figure(Figura *niz, int n){
  for (int i = 0; i < n; i++)
    printf("%s %s %u\n", niz[i].ime, niz[i].boja, niz[i].povrsina);
}

int uporedi(const void *a, const void *b){

  Figura *x = (Figura *)a;
  Figura *y = (Figura *)b;
  
  /* po imenu opadajuce */
  if (strcmp(x->ime, y->ime) > 0){
    return -1;
  }

  if (strcmp(x->ime, y->ime) < 0){
    return 1;
  }
  
  /* po boji rastuce */
  if (strcmp(x->boja, y->boja) < 0){
    return -1;
  }
    
  if (strcmp(x->boja, y->boja) > 0){
    return 1;
  }
    
  /* po povrsini opadajuce */
  if (x->povrsina > y->povrsina){
    return -1;
  }
  
  if (x->povrsina < y->povrsina){
    return 1;
  }
  return 0;
}
/***********************************************/
void quick_sort(Figura *niz, int l, int d);
int particionisanje(Figura *niz, int l, int d);
void razmeni(Figura *niz, int i, int j);
/***********************************************/

int main(int argc, const char *argv[]){

  if (argc != 2)
    greska();
    
  FILE *dat = fopen(argv[1], "r");
  if (NULL == dat)
    greska();

   int n;
  fscanf(dat, "%d", &n);

  Figura *podaci_o_figurama = malloc(n * sizeof(Figura));
  if (NULL == podaci_o_figurama)
    greska();
    
  ucitaj_figure(podaci_o_figurama, n, dat);
  ispisi_figure(podaci_o_figurama, n);
  putchar('\n');
    
  /* quick_sort(podaci_o_figurama, 0, n-1); */
  qsort(podaci_o_figurama, n, sizeof(Figura), &uporedi);

  ispisi_figure(podaci_o_figurama, n);

  fclose(dat);
  free(podaci_o_figurama);
  return 0;
}








/*******************************************************************/
void razmeni(Figura *niz, int i, int j)
{
    Figura tmp;
    strcpy(tmp.ime, niz[i].ime);
    strcpy(tmp.boja, niz[i].boja);
    tmp.povrsina = niz[i].povrsina;

    strcpy(niz[i].ime, niz[j].ime);
    strcpy(niz[i].boja, niz[j].boja);
    niz[i].povrsina = niz[j].povrsina;

    strcpy(niz[j].ime, tmp.ime);
    strcpy(niz[j].boja, tmp.boja);
    niz[j].povrsina = tmp.povrsina;
}

int particionisanje(Figura *niz, int l, int d)
{
    int pivot = l;
    for (int i = l+1; i <= d; i++)
    {
        if (uporedi((void *)&niz[i], (void *)&niz[l]) == -1)
        {
            pivot++;
            razmeni(niz, i, pivot);
        }
    }

    razmeni(niz, l, pivot);
    return pivot;
}

void quick_sort(Figura *niz, int l, int d)
{
    if (l >= d)
    {
        return;
    }
    
    int pivot = particionisanje(niz, l, d);
    
    quick_sort(niz, l, pivot - 1);
    quick_sort(niz, pivot + 1, d);
}
/********************************************************************/