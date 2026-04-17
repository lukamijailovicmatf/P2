#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

void tabela(int n, double a, double b, double (*fp)(double)){

  double x;
  printf("---------------------\n");

  for(int i=0;i<n;i++){
    x=a+i*(b-a)/(n-1);
    printf("| %8.5f | %8.5f |\n", x, (*fp)(x));

  }
  printf("---------------------\n");
}

double sqr(double x){
  return x*x;
}

int main(int argc,char **argv){

  double a,b;
  int n;
  char ime_funkcije[6];
  double (*fp)(double);
  
  if(argc!=2)
    greska();
  
  strcpy(ime_funkcije,argv[1]);

  printf("Unesite broj ekvidistantnih tacaka na mrezi: ");
  scanf("%d",&n);
  if(n<2)
    greska();
  
  printf("Unesite krajeve intervala:\n");
  scanf("%lf %lf",&a,&b);

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


  printf("Funkcija koju tabeliramo: %s\n",ime_funkcije);
  tabela(n,a,b,fp);

  return 0;
}
