#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska();

int main(int argc, char* argv[])
{
    // provera broja argumenata komandne linije
    if(argc == 1)
        greska();
    
    // racunanje a, b, c (min, max, prosecna_vr)
    int min, max;
    float prosecna_vr;
    min = max = prosecna_vr = atoi(argv[1]);

    int i, br;
    for(i = 2; i < argc; i++) {
        br = atoi(argv[i]);
        if(min > br)
            min = br;
        if(max < br)
            max = br;
        prosecna_vr += br;
    }
    prosecna_vr /= (float)(argc - 1);

    // ispis brojeva koji prolaze uslov
    for(i = 1; i < argc; i++) {
        br = atoi(argv[i]);
        if(br > (min + max + prosecna_vr)/3)
            printf("%d ", br);
    }
    printf("\n");

    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}