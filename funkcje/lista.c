#include "../header/lista.h"


int2 listaStart(wezel *wsk)
{
    time_t wsk_sekund;
    time (&wsk_sekund);
    struct tm *tmp;//time.h
    tmp=localtime(&wsk_sekund);
    wsk->nast=NULL;
    wsk->poprz=NULL;
    wsk->glowa=wsk;
    wsk->dzien=tmp->tm_mday;//dzien miesiaca
    wsk->dzienTyg=tmp->tm_mday%7;// jaki dzien tyg
    wsk->miesiac=tmp->tm_mon;// nr miesiaca
    wsk->rok=1900+tmp->tm_year;//lata od 1900
    wsk->tekst[0]='\0';
    wsk->wydarzenie=1;
    return 1;
}
uint2 sprawdzDzien(wezel *wsk)
{
    uint2 dniWMiesiacu[12]= {31,28,31,30,31,30,31,31,30,31,30,31};// tablica dni w miesciacu
    if(wsk->miesiac==1)
    {
        if ((wsk->rok%4==0&&wsk->rok%100!=0)||(wsk->rok%400==0))
            dniWMiesiacu[1]=29;
        else
            dniWMiesiacu[1]=28;
    }
    return dniWMiesiacu[wsk->miesiac];

}
wezel* dodajWezel (wezel *lista)
{
    wezel *wsk,*nowy;
    wsk=lista;
    while (wsk->nast!=NULL)
    {
        wsk=wsk->nast;
    }
    nowy=(wezel*)malloc(sizeof(wezel));
    if (nowy==NULL)
    {
        printf("Brak pamieci!!!");
        return NULL;
    }
    if (wsk->dzienTyg<6) // liczy który jest dzien tyg od so-pt
        nowy->dzienTyg=wsk->dzienTyg+1;
    else
        nowy->dzienTyg=0;
    if (wsk->dzien<sprawdzDzien(wsk))// sprawdza liczbe dni w miesiacu
    {
        nowy->dzien=wsk->dzien+1;
        nowy->miesiac=wsk->miesiac;
        nowy->rok=wsk->rok;
    }
    else
    {
        nowy->dzien=1;
        nowy->miesiac=wsk->miesiac+1;
        nowy->rok=wsk->rok;
        if (nowy->miesiac>11)
        {
            nowy->miesiac=0;
            nowy->rok=wsk->rok+1;
        }
    }
    nowy->nast=NULL;
    nowy->poprz=wsk;
    nowy->glowa=wsk->glowa;
    wsk->nast=nowy;
    nowy->wydarzenie=1;
    nowy->tekst[0]='\0';
    return nowy;
}

wezel* kalendarzNast(wezel *wsk)
{
    if(wsk->nast==NULL)
    {
        wsk=dodajWezel(wsk);
    }
    else
    {
        wsk=wsk->nast;
    }
    return wsk;
}

wezel* kalendarzNastZOpis(wezel *wsk)
{
    while (wsk->nast!=NULL)
    {
        wsk=wsk->nast;
        if (wsk->tekst[0]!='\0')
            return wsk;
    }
    return wsk;
}
wezel* kalendarzPoprzZOpis(wezel *wsk)
{
    while (wsk->poprz!=NULL)
    {
        wsk=wsk->poprz;
        if (wsk->tekst[0]!='\0')
            return wsk;
    }
    return wsk;
}
wezel* kalendarzPoprz(wezel *wsk)
{

    if(wsk->poprz==NULL)
    {
        return wsk;
    }
    else
    {
        wsk=wsk->poprz;
    }
    return wsk;
}

uint2 wyczyscliste(wezel *wsk)
{
    wezel *wsk2;
    while (wsk->nast!=NULL)
    {
        wsk=wsk->nast;
    }
    while (wsk->poprz!=NULL)
    {
        wsk2=wsk;
        wsk=wsk->poprz;
        wsk->nast=NULL;
        free(wsk2);
    }
    return 1;
}
