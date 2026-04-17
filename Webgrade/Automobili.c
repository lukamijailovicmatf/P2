#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXDAT 20
#define MAXNAZ 30

void greska()
{
  fprintf(stderr,"-1\n");
  exit(EXIT_SUCCESS);
}

typedef struct
{
  char naziv[MAXNAZ];
  char marka[MAXNAZ];
  int cena;
} Automobil;

int main(int argc, char* argv[])
{
	
	if(argc!=2)
	  greska();
	int budzet=atoi(argv[1]);
	if(budzet<=0)
	  greska();
	
	char ulazniFajl[MAXDAT];
	scanf("%s", ulazniFajl);
	FILE* ulaz=fopen(ulazniFajl, "r");
	
	if(ulaz==NULL)
	  greska();
	
	int brojAutomobila;
	if(fscanf(ulaz, "%d", &brojAutomobila)<1)
	  greska();
	
	Automobil *automobili=malloc(brojAutomobila*sizeof(Automobil));
	if(automobili==NULL)
	  greska();
	
	int brojac=0;
 	int *indeksi;
	
	for(int i=0; i<brojAutomobila; i++)
	{
	  fscanf(ulaz, "%s %s %d", automobili[i].naziv, automobili[i].marka, &automobili[i].cena);
	}
	
	for(int i=0; i<brojAutomobila; i++)
	{
	  int tCena=automobili[i].cena;

	  if(tCena<=budzet)
	  {
	    brojac++;
	    char tNaziv[MAXNAZ];
	    char tMarka[MAXNAZ];
	    strcpy(tNaziv, automobili[i].naziv);
	    strcpy(tMarka, automobili[i].marka);
			
	    int suma=0;
	    int broj=0;
	    for(int j=0; j<brojAutomobila; j++)
	    {
	        if(strcmp(automobili[j].naziv, tNaziv)==0)
		{
		  suma+=automobili[j].cena;
		  broj++;
		}
	     }
	      float prosek;
	      prosek=(1.0*suma)/broj;
	      printf("%s %s %d [Prosek za %s: %g]\n", tNaziv, tMarka, tCena, prosek, tNaziv);
	  }
	}
	if(brojac==0)
	{
		printf("-\n");
		exit(EXIT_SUCCESS);
	}
	
 	
	free(automobili);
	fclose(ulaz);
	
	return 0;
}