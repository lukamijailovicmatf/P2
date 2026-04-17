#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 11
#define EPS 0.0001

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

double vrednost_polinoma(double *coefs, double x){
  double result=0;
  for(int i=MAX-1; i>=0;i--){
     result=result*x+coefs[i];
  }
  return result;
}

double nula(double *c, double a, double b){
  if(a>b)
    greska();
  
  double s=a+(b-a)/2;
  double value=vrednost_polinoma(c, s);
  if(fabs(value)<EPS)
    return s;
  else {
    double tmp=vrednost_polinoma(c, a);
    if(tmp*value<0)
      return nula(c, a, s);
    else
      return nula(c, s, b);  
  }  
    
}

int main(int argc, char* argv[]){
  
  if(argc!=3)
    greska();
  
  double a=atof(argv[1]);
  double b=atof(argv[2]);  
  
  double coefs[MAX];
  for(int i=0;i<MAX;i++){
     scanf("%lf", &coefs[i]);
  }
 
  printf("Nula unetog polinoma nalazi se u tacki: %.2lf\n", nula(coefs, a, b));

  return 0;
}
