#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 22

typedef struct{
  char ime_cokolade[MAX];
  int gramaza;
  struct cvor *sledeci;
}Cvor;

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

void ispisi(Cvor *lista){

  for (; lista != NULL; lista = lista->sledeci)
    printf("%s %d\n", lista->ime_cokolade, lista->gramaza);
}

void oslobodi_listu(Cvor *lista){

  while (lista != NULL){
    Cvor *tmp = lista;
    lista = lista->sledeci;
    free(tmp);
  }
}

void razmeni_podatke(Cvor *p1, Cvor *p2){

  char tmp_ime[MAX];
  int tmp_grami;

  strcpy(tmp_ime, p1->ime_cokolade);
  tmp_grami = p1->gramaza;

  strcpy(p1->ime_cokolade, p2->ime_cokolade);
  p1->gramaza = p2->gramaza;

  strcpy(p2->ime_cokolade, tmp_ime);
  p2->gramaza = tmp_grami;
}

Cvor *napravi_cvor(char *ime, int grami){

  Cvor *novi = malloc(sizeof(Cvor));
  if (NULL == novi)
    return NULL;
    
  strcpy(novi->ime_cokolade, ime);
  novi->gramaza = grami;

  novi->sledeci = NULL;

  return novi;
}

void dodaj_na_kraj(Cvor **glava, char *ime, int grami){
   
  if (NULL == *glava){
    *glava = napravi_cvor(ime, grami);
    if (NULL == *glava)
      greska();
    return;    
  }

  Cvor *p = *glava;
  while (p->sledeci != NULL)
    p = p->sledeci;

  Cvor *novi = napravi_cvor(ime, grami);
  if (NULL == novi){
    oslobodi_listu(*glava);
    greska();
  }
  p->sledeci = novi;
}

void izbrisi(Cvor *glava, char *ime, int grami){

    if (NULL == glava)
    {
        return;
    }

    if (NULL == glava->sledeci)
    {
        if (strcmp(glava->ime_cokolade, ime) == 0 || glava->gramaza < grami)
        {
            free(glava);
            return;
        }
    }
    
    
    Cvor *naredni = glava->sledeci;
    while (naredni != NULL)
    {
        if (strcmp(glava->ime_cokolade, ime) == 0 || glava->gramaza < grami)
        {
            glava->sledeci = naredni->sledeci;
            razmeni_podatke(glava, naredni);
            free(naredni);
            naredni = glava->sledeci;
        }
        else
        {
            glava = glava->sledeci;
            naredni = naredni->sledeci;
        }
    }
}

int main(int argc, const char *argv[]){

  if (argc != 3)
    greska();

  Cvor *lista = NULL;
  char tmp_ime[MAX + 1];
  int tmp_grama;

  while (scanf("%s%d", tmp_ime, &tmp_grama) != EOF)
    dodaj_na_kraj(&lista, tmp_ime, tmp_grama);

  char ime_kljuc[MAX + 1];
  strcpy(ime_kljuc, argv[1]);
  int grama_kljuc = atoi(argv[2]);
  izbrisi(lista, ime_kljuc, grama_kljuc);

  ispisi(lista);

  oslobodi_listu(lista);
  return 0;
}

