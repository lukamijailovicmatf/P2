#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int main(int argc, const char* argv[]){

  if (argc != 3)
    greska();
    
  FILE* f = fopen(argv[1], "r");
  if (NULL == f)
    greska();
    
  int k = atoi(argv[2]);
  if (k <= 0)
    greska();
    
  char c;
  int br_velikih = 0;
  int br_linija = 0;

  while ((c = fgetc(f)) != EOF){

    if (isupper(c))
      br_velikih++;
        
    if (c == '\n'){
      if (br_velikih >= k)
        br_linija++;
      br_velikih = 0;
    }
  }

  /* za poslednju liniju jer EOF nije '\n' */

  if (br_velikih >= k)
    br_linija++;
    
  printf("%d\n", br_linija);
    
  fclose(f);
  return 0;
}