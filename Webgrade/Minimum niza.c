#include <stdio.h>
#include <stdlib.h>

int maksimum_niza(int* a, int n)
{
	if(n==1)
	  return *a;
	else 
	{
	  int m=maksimum_niza(a+1,n-1);
	  if(*a>m)
	    return *a;
	  else
	    return m;
		
	}
		
	
}

int main()
{
	int n;
	scanf("%d",&n);

	if(n<1)
	{
		fprintf(stderr,"-1\n");
		exit(EXIT_SUCCESS);
	}
	int *a=malloc(n*sizeof(int));
	if(a==NULL)
	{
		fprintf(stderr,"-1\n");
		exit(EXIT_SUCCESS);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("%d\n",maksimum_niza(a,n));
	free(a);
	return 0;
}