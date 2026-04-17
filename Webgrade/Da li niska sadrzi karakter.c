#include <stdio.h>
#define MAX 64

char* sadrzi(char* s, char c)
{
    if(*s==NULL || *s==c)
        return s;
    else
        return sadrzi(s+1,c);
}

int main()
{
    char upis[MAX];
    char c;
    scanf("%s %c",upis,&c);

    char *p=sadrzi(upis,c);
    if(*p==NULL)
        printf("-1\n");
    else
        printf("%d\n",p-upis);

    return 0;
}