#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void greska(){

  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int br_cifara(int x){
   
  int br_cif = 0;
  while (x){

    br_cif++;
    x /= 10;
  }
  return br_cif;
}

int jeste_armstrongov(int x){

  int suma = 0;
  int br_cif = br_cifara(x);
  int cpx = x;

  while (x){

    suma += (int)pow(x%10, br_cif);
    x /= 10;
  }
  return suma==cpx;
}

int main(int argc, char* argv[]){

    /* provera broja argumenata */
    if (argc != 3)
      greska();

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    if (a > b || a < 0 || b < 0)
        greska();
    
    for (int i = a; i <= b; i++){

      if (jeste_armstrongov(i))
        printf("%d ", i);
    }
    putchar('\n');
    
    return 0;
}





