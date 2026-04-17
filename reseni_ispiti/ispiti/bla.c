#include "stabla.h"

int kao_u_ogledalu(Cvor* koren1, Cvor* koren2);

int main()
{
    Cvor* stablo1 = NULL, *stablo2 = NULL;

    int tmp;
    scanf("%d", &tmp);
    while (tmp != 0)
    {
        dodaj_u_stablo(&stablo1, tmp);   
        scanf("%d", &tmp);
    }
    scanf("%d", &tmp);
    while (tmp != 0)
    {
        dodaj_u_stablo(&stablo2, tmp);   
        scanf("%d", &tmp);
    }

    if (kao_u_ogledalu(stablo1, stablo2))
    {
        puts("Jesu.");
    }
    else
    {
        puts("Nisu.");
    }
    

    oslobodi_stablo(stablo1);
    oslobodi_stablo(stablo2);
    return 0;
}

int kao_u_ogledalu(Cvor* koren1, Cvor* koren2)
{
    // ako je samo jedno stablo prazno
    if ((NULL == koren1 && NULL != koren2) || (NULL == koren2 && NULL != koren1))
    {
        return 0;
    }

    // ako su oba stabla prazna
    if (NULL == koren1 && NULL == koren2)
    {
        return 1;
    }
    
    if ((NULL == koren1->levo && NULL == koren2->desno) || (NULL == koren1->desno && NULL == koren2->levo))
    {
        return 1;
    }
    else if ((NULL != koren1->levo && NULL != koren2->desno) || (NULL == koren1->desno && NULL == koren2->levo))
    {
        
    }
    else if ((NULL == koren1->levo && NULL == koren2->desno) || (NULL != koren1->desno && NULL != koren2->levo))
    {
        
    }
    else
    {
        return 0;
    }
    
    int rez = kao_u_ogledalu(koren1->levo, koren2->desno);
    return rez * kao_u_ogledalu(koren1->desno, koren2->levo);
}