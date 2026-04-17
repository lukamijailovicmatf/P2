#include <stdio.h>
#include <string.h>
#define MAX 64

char* podniska(char* s1, char* s2)
{
    if(*s2==NULL || strncmp(s1, s2, strlen(s1))==0)
        return s2;
    else
        return podniska(s1,s2+1);
    
}

int main()
{
    char prvi[MAX];
    char drugi[MAX];
    scanf("%s %s",prvi,drugi);

    char *p = podniska(prvi,drugi);

    if(*p!=NULL)
        printf("%d\n", p-drugi);
    else
        printf("-1\n");

    return 0;
}