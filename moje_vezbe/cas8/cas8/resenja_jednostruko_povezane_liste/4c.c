#include "liste.h"

Cvor* izbaci3(Cvor* lista, int broj){

/* Ako je lista prazna */
  if (lista == NULL)
    return NULL;
		
/* Izbacujemo glavu */
  if (lista->vrednost == broj){
    Cvor *pom = lista->sledeci;
    free(lista);
    return izbaci3(pom, broj);
  }else{
    lista->sledeci = izbaci3(lista->sledeci, broj);
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
	
  lista2 = izbaci3(lista1, xbroj);
  printf("Lista nakon izbacivanja %d:\n", broj);
  ispisi_listu(lista2, stdout);

  oslobodi_listu(lista2);

  return 0;
}