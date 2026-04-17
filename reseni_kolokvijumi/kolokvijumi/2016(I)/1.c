#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000
#define MIN 2

void greska();
int jeste_prost(int br);

int main(int argc, char** argv) 
{
    if(argc != 3)
        greska();
    
    int k, l;
    k = atoi(argv[1]);
    l = atoi(argv[2]);
    if(k < MIN || k > l || l < k || l > MAX)
        greska();
    
    int i;
    for(i = k; i <= l; i++) {
        if(jeste_prost(i))
            printf("%d ", i);
    }
    printf("\n");
    
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int jeste_prost(int br)
{
    int i;
    for(i = 2; i <= br/2; i++) {
        if(br % i == 0)
            return 0;
    }
    return 1;
}