#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

/* Ispis s desna na levo */

void ispis2(int x){
  if(x<10){
    printf("%d", x);
    return;
  }
  
  printf("%d", x%10);
  ispis2(x/10);
}

//ispis s leva na desno
void ispis1(int x){
  if(x<10){
    printf("%d", x);
    return;
  }
  
  ispis1(x/10);
  printf("%d", x%10);
}

//ispis sa leva na desno
void ispis3(int x){
  if(x<10){
    printf("%d", x);
    return;
  }
  
  int p=1;
  int tmp=x;
  while(tmp>10){
    tmp=tmp/10;
    p*=10;
  }
  
  printf("%d", tmp);
  //1234-1000
  ispis3(x-tmp*p);
}

int broj_parnih(int x){
   if(x<10 && x%2==0){
     return 1;
   }
   //!!!!
   if(x<10){
     return 0;
   }
   
   if(x%2==0)
     return 1+broj_parnih(x/10);
   else
     return broj_parnih(x/10);  
}

int najveca_cifra(int x){
   if(x<10){
     return x;
   }
   
   int help=najveca_cifra(x/10);
   
   if(x%10>help)
     return x%10;
   else
     return help;  
   
}

int ukloni(int x, int c){
   if(x<10 && x==c){
     return 0;
   }
   //!!!!
   if(x<10){
     return x;
   }
   
   if(x%10==c)
     return ukloni(x/10,c);
   else
     return ukloni(x/10,c)*10+x%10;  
   
}

int broj_cifara(int x){
   if(x<10)
     return 1;
   
   return 1+broj_cifara(x/10);  
}

void napravi_niz(int *kraj_niza, int broj){

   if(broj<10){
     kraj_niza[0]=broj;
     return;
   }
   
   kraj_niza[0]=broj%10;
   napravi_niz(kraj_niza-1, broj/10);
}

void ispisi_niz(int *niz, int n){

   if(n<=0){
     printf("\n");
     return;
   }
   
   printf("%d ", niz[0]);
   ispisi(niz+1, n-1);
}

void heksa_zapis(int x){
  if(x==0)
    return;
  
  heksa_zapis(x/16);
  
  if(x%16<10)
    printf("%d", x%16);
  else {
    printf("%c", 'A'+(x%16-10));
  }    
}

void obrni_niz(int* a, int n){

   if(n<=1)
     return;
   
   int tmp=a[0];
   a[0]=a[n-1];
   a[n-1]=tmp;
   
   obrni_niz(a+1, n-2);  
}

int palindrom(int *niz, int n){

   if(n<=1)
     return 1;
   
   if(niz[0]!=niz[n-1])
     return 0;
   
   return palindrom(niz+1, n-2);    
}

int dodaj_0(int x){

  if(x<10)
    return x;
  
  int levi_deo=dodaj_0(x/10);
                                                
  if(x%2==1)                                    
    return levi_deo*100+x%10;                                                                                                        
  else
    return levi_deo*10+x%10;    
}

int main(){

 int n;
 printf("Unesite neki pozitivan ceo broj: \n");
 scanf("%d", &n);
 if(n<0)
   greska();

 /*

 printf("Ispis cifara broja sa desna na levo: "); 
 
 ispis2(n);

 printf("\n");
 
 printf("\n-----------------------------------\n");

 printf("Ispis cifara broja sa leva na desno: "); 
 
 ispis1(n);

 printf("\n");
 
 printf("\n-----------------------------------\n");

 printf("(Volume 2)Ispis cifara broja sa leva na desno: "); 
 
 ispis3(n);

 printf("\n");

 printf("\n-----------------------------------\n");

 printf("Broj parnih cifara u unetom broju iznosi: %d.\n", broj_parnih(n));

 printf("\n-----------------------------------\n"); 
  
 printf("Najveca cifra u unetom broje je: %d.\n", najveca_cifra(n));
 
 printf("\n-----------------------------------\n");

 printf("Unesite cifru za uklanjanje: \n");

 int c;
 scanf("%d", &c);

 if(c<0 || c>10) 
   greska();

 printf("Broj nakon uklanjanja unete cifre izgleda ovako: %d\n", ukloni(n, c));  
 
 printf("\n-----------------------------------\n");
 */

 int len=broj_cifara(n);
 printf("Broj cifara unetog broja iznosi: %d.\n", len);

 int *niz=(int*)malloc(len*sizeof(int));
 if(niz==NULL)
   greska();
 
 napravi_niz(niz+len-1, n);
 ispisi(niz, len);   
 
 /*

 printf("\n-----------------------------------\n");

 printf("Uneti broj u heksadekadnom zapisu izgleda ovako: ");

 heksa_zapis(n);

 printf("\n");  

 printf("\n-----------------------------------\n"); 
 */

 obrni_niz(niz, len);
 ispisi(niz, len); 
 
 printf("\n-----------------------------------\n"); 

 if(palindrom(niz, len))
   printf("Niz jeste palindrom!\n");
 else
   printf("Niz nije palindrom!\n");  
  
 printf("\n-----------------------------------\n");

 printf("Broj nakon izmene izgleda ovako: %d.\n", dodaj_0(n));  
 
 return 0;
}
