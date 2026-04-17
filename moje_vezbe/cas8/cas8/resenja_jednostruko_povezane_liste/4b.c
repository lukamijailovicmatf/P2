#include "liste.h"

int postoji(Cvor* lista, int broj){

  if (lista == NULL)
    return 0;
		
  if (lista->vrednost == broj)
    return 1;
		
  return postoji(lista->sledeci, broj);
}

/* poslednje pojavljivanje */
Cvor* izbaci2(Cvor* lista, int broj){

  if (lista == NULL)
    return NULL;
		
  if (lista->vrednost == broj && !postoji(lista->sledeci, broj)){

    Cvor *pom = lista->sledeci;
    free(lista);
    return pom;
  }else{
    lista->sledeci = izbaci2(lista->sledeci, broj);
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
	
  lista2 = izbaci2(lista1, broj);
  printf("Lista nakon izbacivanja %d:\n", broj);
  ispisi_listu(lista2, stdout);

  oslobodi_listu(lista2);

  return 0;
}