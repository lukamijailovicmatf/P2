#include "liste.h"

Cvor* dodaj_element(Cvor* lista, int broj){

  if (lista == NULL)
    return napravi_cvor(broj);

  if (lista->vrednost > broj){

    Cvor* novi = napravi_cvor(broj);
    novi->sledeci = lista;
    return novi;
  }else
    lista->sledeci = dodaj_element(lista->sledeci, broj);
    return lista;
}

int main(){

  Cvor *lista1 = NULL;
  Cvor *lista2 = NULL;
  int broj;
	
  printf("Uneti neopadajucu listu:\n");
  lista1 = ucitaj_listu_v2(stdin);

  printf("Uneti broj: ");
  scanf("%d", &broj);
	
  lista2 = dodaj_element(lista1, broj);
  printf("Lista nakon dodavanja elementa 10:\n");
  ispisi_listu(lista2, stdout);

  oslobodi_listu(lista2);

  return 0;
}