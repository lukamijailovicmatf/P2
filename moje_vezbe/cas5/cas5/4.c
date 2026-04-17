#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

double sqr(double x){
  return x*x;
}

double integral(double a, double b, int n, double (*fp)(double)){

  double suma=0;
  double h=(b-a)/n;
  
  for(int i=1;i<=n;i++){
    suma+=(*fp)(a+i*h);
  }
  return h*(((*fp)(a)+(*fp)(b))/2 + suma);
}

int main(){

  double a,b;
  int n;
  char ime_funkcije[6];
  double (*fp)(double);
  
  printf("Unesite ime funkcije, n, a i b:\n");
  scanf("%s %d %lf %lf",ime_funkcije,&n,&a,&b);
  
  if(strcmp(ime_funkcije,"sin")==0)
    fp=&sin;
  else if(strcmp(ime_funkcije,"cos")==0)
    fp=&cos;
  else if(strcmp(ime_funkcije,"tan")==0)
    fp=&tan;
  else if(strcmp(ime_funkcije,"atan")==0)
    fp=&atan;
  else if(strcmp(ime_funkcije,"asin")==0)
    fp=&asin;
  else if(strcmp(ime_funkcije,"acos")==0)
    fp=&acos;
  else if(strcmp(ime_funkcije,"exp")==0)
    fp=&exp;
  else if(strcmp(ime_funkcije,"log")==0)
    fp=&log;
  else if(strcmp(ime_funkcije,"log10")==0)
    fp=&log10;
  else if(strcmp(ime_funkcije,"sqrt")==0)
    fp=&sqrt;
  else if(strcmp(ime_funkcije,"floor")==0)
    fp=&floor;
  else if(strcmp(ime_funkcije,"ceil")==0)
    fp=&ceil;
  else if(strcmp(ime_funkcije,"sqr")==0)
    fp=&sqr;
  else
    greska();

  printf("Vrednost integrala je: %lf\n",integral(a, b, n, fp));

  return 0;
}
