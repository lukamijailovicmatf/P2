#include <stdio.h>
#define MAX 64

int poredi(char* s1, char* s2)
{
    if(*s1!=*s2)
        return 1;
    else
    {
        if(*s1=='\0')  
            return 0;
        else
            return poredi(s1+1,s2+1);
    }
}

int main()
{
    char prvi[MAX];
    char drugi[MAX];
    while(scanf("%s %s", prvi, drugi)!=EOF)
    {
        printf("%d", poredi(prvi, drugi));
    }
    return 0;
}