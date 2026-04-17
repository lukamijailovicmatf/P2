#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska()
{
	fprintf(stderr,"-1\n");
	exit(EXIT_SUCCESS);
}

typedef struct
{
	int brojilac,imenilac;
} 	Razlomak;

int main(int argc, char* argv[])
{
	
	if(argc!=4)
	  greska();
	
	FILE* ulaz=fopen(argv[1],"r");
	FILE* izlaz=fopen(argv[2],"w");
	
	if(ulaz==NULL || izlaz==NULL)
	  greska();
	
	int brojRazlomaka;
	if(fscanf(ulaz,"%d",&brojRazlomaka)<1)
	  greska();
	
	Razlomak *razlomci=malloc(brojRazlomaka*sizeof(Razlomak));
	if(razlomci==NULL)
	  greska();
	
	for(int i=0; i<brojRazlomaka; i++)
	{
	  fscanf(ulaz, "%d/%d", &razlomci[i].brojilac, &razlomci[i].imenilac);
	  if(razlomci[i].imenilac==0 || razlomci[i].brojilac==0)
	    greska();
	  if(razlomci[i].imenilac<0 && razlomci[i].brojilac<0)
	  {
	    razlomci[i].imenilac*=-1;
	    razlomci[i].brojilac*=-1;
	  }
	  else if(razlomci[i].brojilac<0)
	  {
	    razlomci[i].imenilac*=-1;
	    razlomci[i].brojilac*=-1;
	  }
	}
	
	if(strcmp(argv[3],"-x")==0)
	{
	  for(int i=0; i<brojRazlomaka; i++)
	  {
	    fprintf(izlaz, "%d/%d\n", razlomci[i].imenilac, razlomci[i].brojilac);
			
	  }
		
	}
	
	else if(strcmp(argv[3],"-y")==0)
	{
	  for(int i=0; i<brojRazlomaka; i++)
	  {
	    fprintf(izlaz, "%g\n", (1.0*razlomci[i].imenilac)/razlomci[i].brojilac);
			
	  }
	}
	
	else if(strcmp(argv[3],"-xy")==0 || strcmp(argv[3],"-yx")==0)
	{
	  for(int i=0; i<brojRazlomaka; i++)
	  {
	    fprintf(izlaz, "%d/%d %g\n", razlomci[i].imenilac, razlomci[i].brojilac, (1.0*razlomci[i].imenilac)/razlomci[i].brojilac);
			
	  }
	}
	
	else greska();
	
	free(razlomci);
	fclose(ulaz);
	fclose(izlaz);
	
	return 0;
}