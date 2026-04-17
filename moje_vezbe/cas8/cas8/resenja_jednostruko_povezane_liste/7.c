#include "liste.h"

Cvor* umetni(Cvor* lista, int k){

  if (lista == NULL)
    return NULL;
		
  if (lista->sledeci == NULL)
    return lista;

  if (lista->vrednost + lista->sledeci->vrednost == k || abs(lista->vrednost - lista->sledeci->vrednost) == k){

    /* Treba umetnuti -1 */
    Cvor *novi = napravi_cvor(-1);
    novi->sledeci = lista->sledeci;
    lista->sledeci = novi;
	
    novi->sledeci = umetni(novi->sledeci, k);	
    return lista;
  }else{
    /* Nista se ne umece */
    lista->sledeci = umetni(lista->sledeci, k);
    return lista;
  }
}


int main(){

  Cvor *lista1 = NULL;
  Cvor *lista2 = NULL;
  int k;
	
  printf("Uneti listu:\n");
  lista1 = ucitaj_listu_v2(stdin);

  printf("Uneti broj: ");
  scanf("%d", &k);

  lista2 = umetni(lista1, k);
  ispisi_listu(lista2, stdout);

  oslobodi_listu(lista2);
  return 0;
}