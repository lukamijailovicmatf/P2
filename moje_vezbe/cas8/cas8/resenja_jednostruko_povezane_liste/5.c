#include "liste.h"

Cvor* naizmenicno(Cvor* lista1, Cvor* lista2){

  if (lista1 == NULL)
    return lista2;

  if (lista2 == NULL)
    return lista1;
		
  lista1->sledeci = naizmenicno(lista2, lista1->sledeci);
	
  return lista1;
}

int main(){

  Cvor *lista1 = NULL;
  Cvor *lista2 = NULL;
  Cvor *lista3 = NULL;
	
  printf("Uneti prvu listu:\n");
  lista1 = ucitaj_listu_v2(stdin);
  printf("Uneti drugu listu:\n");
  ucitaj_listu(&lista2, stdin);

  printf("Naizmenicno dobijena lista je:\n");
  lista3 = naizmenicno(lista1, lista2);
  ispisi_listu(lista3, stdout);
	
  /* osloboditi listu */
  oslobodi_listu(lista3);


  return 0;
}