#include "liste.h"

int veci_od(Cvor* lista, int broj){

  if (lista == NULL)
    return 0;

  if (lista->vrednost > broj)
    return veci_od(lista->sledeci, broj) + 1;
  else
    return veci_od(lista->sledeci, broj);
}

int main(){

  Cvor *lista1 = NULL;
  int broj;
	
  printf("Uneti listu:\n");
  lista1 = ucitaj_listu_v2(stdin);

  printf("Uneti broj: ");
  scanf("%d", &broj);
	
  printf("Broj elementa vecih od broja %d u listi1 su %d\n", broj, veci_od(lista1, broj));

  oslobodi_listu(lista1);

  return 0;
}