#include "../header/operacje.h"



uint2 ukryjBezOpisu(wezel *adres)
{
    while(adres!=NULL)
    {
        if (adres->tekst[0]=='\0')
        {
            adres->wydarzenie=0;
        }
        adres=adres->nast;
    }
    return 1;
}

uint2 pokazBezOpisu(wezel *adres)
{
    while(adres!=NULL)
    {
        adres->wydarzenie=1;
        adres=adres->nast;
    }
    return 1;
}
