#include <stdio.h>
#include <stdlib.h>

#define MAX_LINIJA 81

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int main(){

  FILE *ulaz, *izlaz;
  char linija[MAX_LINIJA];

  ulaz = fopen("1_ulaz.txt", "r");
  if(ulaz == NULL)
    greska();

  izlaz = fopen("izlaz.txt", "w");
  if(izlaz == NULL)
    greska();
	
/* Obrada ulaza */

  char c;

/* Karakter po karakter I nacin */

  while(fscanf(ulaz, "%c", &c) != EOF)
	fprintf(izlaz, "%c", c);
	
/* Karakter po karakter II nacin */

  /* fgetc(fajl) -- getchar() */
	
  while((c = fgetc(ulaz)) != EOF){
	fputc(c, izlaz);
  }

/* Linija po linija */

  while(fgets(linija, MAX_LINIJA, ulaz) != NULL)
	fputs(linija, izlaz);

  while(fgets(linija, MAX_LINIJA, ulaz) != NULL)
	fprintf(izlaz, "%s", linija);

  fclose(ulaz);
  fclose(izlaz);
  return 0;
}
