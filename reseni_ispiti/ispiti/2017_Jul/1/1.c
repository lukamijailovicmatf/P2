#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

void ispisi(char* s, int p, FILE* f){

  char* podniska = malloc((p+1) * sizeof(char));  /* +1 za '\0' */
  if (NULL == podniska)
    greska();
    
  int i = 0;
  while (i + p - 1 != (int)strlen(s)){

    strncpy(podniska, (s+i), p);
    podniska[p] = '\0';
    fprintf(f, "%s ", podniska);

    i++;
  }
  free(podniska);
}

int main(int argc, const char* argv[]){

  if (argc != 3)
    greska();
    
    int p = atoi(argv[1]);
    if (p <= 0)
      greska();
    
    char* s;
    sscanf(argv[2], "%ms", &s);
    
    if (p > (int)strlen(s))
      greska();
    

    FILE* f = fopen("podniske.txt", "w");
    if (NULL == f)
      greska();

    ispisi(s, p, f);

    free(s);
    fclose(f);
    return 0;
}