#include "liste.h"

Cvor* izbaci3(Cvor* lista, int x)
{
	if (lista == NULL)
		return NULL;
		
	//izbacujemo glavu
	if (lista->vrednost == x)
	{
	  Cvor *pom = lista->sledeci;
		free(lista);
		return izbaci3(pom, x);
	}
	
	else
	{
		lista->sledeci = izbaci3(lista->sledeci, x);
		return lista;
	}
}

int minimum(Cvor* lista)
{
	if (lista->sledeci == NULL)
		return lista->vrednost;
		
	int pom = minimum(lista->sledeci);
	
	if (pom < lista->vrednost)
		return pom;
	else
		return lista->vrednost;
}

// Zadatak sa ispita
// Iz date liste izbaciti 2 najmanja.
// Izbaciti sva pojavljivanja i pri tome 2 razlicita najmanja.
Cvor* izbaci_2min(Cvor* lista)
{
	int min;

	if (lista != NULL) {
		//nadji minimum
		min = minimum(lista);
		//izbaci minimum
		lista = izbaci3(lista, min);
	}
	
	if (lista != NULL) {
		//nadji 2. minimum
		min = minimum(lista);
		//izbaci minimum
		lista = izbaci3(lista, min);
	}
	
	return lista;
}

int main()
{
	Cvor *lista1 = NULL;
	Cvor *lista2 = NULL;
	
	printf("Uneti listu:\n");
	lista1 = ucitaj_listu_v2(stdin);

	lista2 = izbaci_2min(lista1);
	ispisi_listu(lista2, stdout);

	oslobodi_listu(lista2);
	return 0;
}