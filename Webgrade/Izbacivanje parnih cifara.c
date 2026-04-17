#include <stdio.h>
#include <stdlib.h>

void greska()
{
	fprintf(stderr,"-1\n");
	exit(EXIT_SUCCESS);
}

int izbaci_parne(int x)
{
	if(x==0)
	  return 0;
	else if(x%2==1)
	  return x%10+izbaci_parne(x/10)*10;
	else
	  return izbaci_parne(x/10);
}

int main(int argc, char* argv[])
{
	if(argc!=2)
	  greska();

	int broj=atoi(argv[1]);
	int znak=(broj>0) ? 1:-1;
	broj=abs(broj);
	printf("%d\n",znak*izbaci_parne(broj));
	return 0;
}