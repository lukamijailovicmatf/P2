#include "liste.h"

Cvor* izbaci1(Cvor* lista, int broj){

  if (lista == NULL)
    return NULL;
		
  /* izbacujemo glavu */
  if (lista->vrednost == broj){

    Cvor *pom = lista->sledeci;
    free(lista);
    return pom;
  }else{
    lista->sledeci = izbaci1(lista->sledeci, broj);
    return lista;
  }
}

int main(){

  Cvor *lista1 = NULL;
  Cvor *lista2 = NULL;
  int broj;
	
  printf("Uneti listu:\n");
  lista1 = ucitaj_listu_v2(stdin);

  printf("Uneti broj: ");
  scanf("%d", &broj);
	
  lista2 = izbaci1(lista1, broj);
  printf("Zadatak 4a: Lista nakon izbacivanja %x:\n", broj);
  ispisi_listu(lista2, stdout);

  oslobodi_listu(lista2);

  return 0;
}