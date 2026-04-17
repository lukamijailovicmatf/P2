#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GORNJA_GRANICA 10000
#define DONJA_GRANICA 0

void greska();
int zbir_cifara(int br);

int main(int argc, char* argv[])
{   
    // provera broja argumenata
    if(argc != 3)
        greska();
    
    // ucitavanje a i b sa komandne linije
    int a, b;
    a = atoi(argv[1]);
    b = atoi(argv[2]);

    // provera a i b
    if(a < DONJA_GRANICA || b < a || b > GORNJA_GRANICA || a > b)
        greska();

    // racunanje rezultata
    int i, rezultat = 0;
    for(i = a; i<= b; i++) {
        rezultat += zbir_cifara(i);
    }
    
    // ispis rezultata
    printf("%d\n", rezultat);

    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int zbir_cifara(int br) 
{
    int zbir = 0;
    while(br) {
        zbir += br%10;
        br /= 10;
    }

    return zbir;
}