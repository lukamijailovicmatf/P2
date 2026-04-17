/*
Parametri komandne linije su n, a, b (a < b). Na standardni izlaz ispisati n slucajnih brojeva
koji su izmedju a i b. U slucaju greske na standardni izlaz za greske ispisati -1.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

int main(int argc, char*argv[]){
  
  if(argc!=4){
    greska();
  }
  int n=atoi(argv[1]);
  int a=atoi(argv[2]);
  int b=atoi(argv[3]);
  if(a>=b)
    greska();
  srand(time(NULL));  
  for(int i=1;i<=n;i++){
     double x=(double)rand()/RAND_MAX;
     printf("%.2f ", a+(b-a)*x);
  } 
  printf("\n"); 

  return 0;
}

