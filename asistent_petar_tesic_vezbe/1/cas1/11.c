/*
Napraviti funkciju koja generise slucajan realan broj od 0 i 1. Na standardni izlaz ispisati rezultat
izvrsavanja napisane funkcije.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){

 srand(time(NULL));
 double x=(double)rand()/RAND_MAX;
 printf("%.2lf\n", x);
 
 return 0;
}
