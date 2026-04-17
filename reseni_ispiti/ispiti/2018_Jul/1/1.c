#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 21

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int jeste_palindrom(const char* s){

  int i = 0, j = strlen(s)-1;

  while (i < j){
    if (tolower(s[i]) != tolower(s[j]))
      return 0;

    i++;
    j--;
  }
  return 1;
}

void ispisi_odgovarajuce_linije(FILE* f){

  char s[MAX];
  char* linija = NULL;
  long unsigned n = 0;

  int k, procitano;

  while (getline(&linija, &n, f) != EOF){
    procitano = 0;
    while (sscanf(linija+procitano, "%s %n", s, &k) == 1){
       if (strlen(s) > 2 && jeste_palindrom(s)){
         fputs(linija, stdout);
           break;
       }
       procitano += k+1;   // +1 zbog spejsa
    }
  }
  printf("\n");
  free(linija);
}

int main(int argc, const char* argv[]){

  if (argc != 2)
    greska();

  FILE* f = fopen(argv[1], "r");
  if (NULL == f)
    greska();

  ispisi_odgovarajuce_linije(f);
    
  fclose(f);
  return 0;
}