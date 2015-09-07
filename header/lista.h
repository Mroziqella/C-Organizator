#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "mysys.h"
#include <time.h>

#define DLUGOSC_TEKSTU 255

typedef struct wezel
{
    struct wezel *nast,*poprz,*glowa;
    uint2 dzien;
    uint2 miesiac;
    uint2 rok;
    uint2 dzienTyg;
    char tekst[DLUGOSC_TEKSTU];
    uint2 wydarzenie;
}wezel;

int2 listaStart(wezel *wsk);
wezel* dodajWezel (wezel *lista);
uint2 sprawdzDzien(wezel *wsk);
wezel* kalendarzNast(wezel *wsk);
wezel* kalendarzPoprz(wezel *wsk);
uint2 wyczyscliste(wezel *wsk);
wezel* kalendarzNastZOpis(wezel *wsk);
wezel* kalendarzPoprzZOpis(wezel *wsk);

#endif // LISTA_H_INCLUDED
