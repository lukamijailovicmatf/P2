#include"lista.h"
#include<stdio.h>
#include<stdlib.h>

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

Cvor* napravi_cvor(int broj){
  Cvor* novi = malloc(sizeof(Cvor));
  if(novi == NULL)
    greska();
  
  novi->vrednost = broj;
  novi->sledeci = NULL;
 
  return novi;
}

void dodaj_na_pocetak(Cvor** lista, int broj){
    Cvor* novi = napravi_cvor(broj);    
    novi->sledeci = *lista;
    *lista = novi;
}

void ispisi_listu(Cvor* lista){
  /*u slucaju prazne lista, ako necemo da ispisujemo [] vec hocemo da 
    bude prazno, pre svih naredbi  cemo reci if(lista==NULL) return;*/
  
  printf("[");
  while(lista != NULL){
    printf("%d", lista->vrednost);
    if(lista->sledeci)
      printf(", ");
    lista = lista->sledeci;
  }
  printf("]\n");
  
}

void dodaj_na_kraj(Cvor** lista, int broj){
  if(*lista == NULL){
    Cvor* novi = napravi_cvor(broj);
    *lista = novi;
    return;
  }
  
  dodaj_na_kraj(&(*lista)->sledeci, broj);
}


//druga verzija funkcije dodaj_na_kraj
Cvor *dodaj_na_kraj1(Cvor *lista,int broj){
  Cvor *novi=napravi_cvor(broj);
  if(novi==NULL)
    greska();
  
  if(lista==NULL)
    return novi;

  Cvor *tmp=lista;
  while(tmp->sledeci)
    tmp=tmp->sledeci;

  tmp->sledeci=novi;
  
  return lista;
}

//funkcija koja ucitava listu do EOF-a pomocu funkcije dodaj_na_kraj1
Cvor* ucitaj_listu(Cvor* lista, FILE* f){
    if(f == NULL)
        greska();
    int x;
    while(fscanf(f, "%d", &x) != EOF){
      // if(x==0)
	  // break;
      lista=dodaj_na_kraj1(lista, x);
    }
    return lista;
}

/*
Cvor* ucitaj_listu(Cvor* lista, FILE* f){
    if(f == NULL)
        greska();
    int x;
    while(fscanf(f, "%d", &x) != EOF){
      lista=dodaj_na_kraj1(lista, x);
    }
    return lista;
}
*/

//funkcija koja ucitava listu do unosa 0 pomocu funkcije dodaj_na_kraj
void ucitaj_listu1(Cvor **lista,FILE *f){
  int x;
  
  while(1){
    fscanf(f, "%d", &x);
    /*
    if(x==0)
      break;
    */
    dodaj_na_kraj(lista, x);
  }
  
  return ;
}

/*
void ucitaj_listu1(Cvor **lista,FILE *f){
  int x;
  
  while(fscanf(f, "%d", &x)!=EOF){
    dodaj_na_kraj(lista, x);
  }
  
  return ;
}
*/


void oslobodi_listu(Cvor* lista){
  if(lista){
    oslobodi_listu(lista->sledeci);
    free(lista);
  }
}

//NAPOMENA: ova funkcija NECE biti na raspolaganju na ispitu
void obrisi_cvor(Cvor** lista, int broj){
  if(*lista == NULL)
    return;
  else if((*lista)->vrednost == broj){
    Cvor* tmp = *lista;
    *lista = (*lista)->sledeci;
    free(tmp);
    obrisi_cvor(lista, broj);
  }
  else
    obrisi_cvor(&(*lista)->sledeci, broj);
}