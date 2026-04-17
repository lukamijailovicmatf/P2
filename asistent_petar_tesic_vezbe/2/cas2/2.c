/*
Napisati program koji sa standardnog ulaza uˇcitava niz razlomaka. Prvo se uˇcita broj razlomaka,
a zatim i razlomci u obliku brojilac imenilac. Na standardni izlaz ispisati sve razlomke ˇcija je vrednost ve ́ca
od proseˇcne vrednosti svih uˇcitanih razlomaka, u obliku brojilac/imenilac. Ne praviti nikakve pretpostavke o
maksimalnoj dimenziji niza. U sluˇcaju greˇske na standardni izlaz za greˇske ispisati -1.
*/
#include <stdio.h>
#include <stdlib.h>

int main(){

  int n;
  scanf("%d", &n);
  int *br=(int *)malloc(n*sizeof(int));
  int *im=(int *)malloc(n*sizeof(int));
  if(br==NULL || im==NULL || n<=0){
    fprintf(stderr,"-1");
    exit(EXIT_FAILURE);
  }

  float avg=0;
  for(int i=0;i<n;i++){
     scanf("%d %d", &br[i], &im[i]);
     if(im[i]==0){
       fprintf(stderr,"-1");
       exit(EXIT_FAILURE);
     }
     avg+=(float)br[i]/im[i];
  }
  avg/=n;
  
  for(int i=0;i<n;i++){
     if((float)br[i]/im[i]>avg)
       printf("%d/%d\n", br[i], im[i]);
  }
  
  
  free(br);
  free(im);

 return 0;
}
