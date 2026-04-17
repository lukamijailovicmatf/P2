#include <stdio.h>
#include <stdlib.h>

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int jeste_nivenov(int x){

  int suma_cifara = 0; 
  int cpx = x;
  while (cpx){
    suma_cifara += cpx % 10;
    cpx /= 10;
  }
  if (x % suma_cifara == 0)
    return 1;

  return 0;
}

int main(int argc, const char* argv[]){

  if (argc != 2)
    greska();

  int n = atoi(argv[1]);
  if (n <= 0)
    greska();
    
  int suma = 0;
  int br = 0; 
  int x;
  for (int i = 0; i < n; i++){
    scanf("%d", &x);
      if (x < 0)
        greska();
        
    if (jeste_nivenov(x)){
      suma += x;
      br++;
    }
  }
    
  if (br)
    printf("%.2lf\n", (double)suma/br);
  else
    printf("0.00\n");
    
    
  return 0;
}