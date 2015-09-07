#ifndef IN_OUT_H_INCLUDED
#define IN_OUT_H_INCLUDED


#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>


#include "lista.h"
#include "mysys.h"
#include "teksty.h"
#include "operacje.h"

#define ROZMIAR_SCIEZKI 10

#define ENTER 13
#define ESC 27

#define KAL         "Kalendarz          "
#define EKS         "Eksportuj          "
#define POD         "Podglad            "
#define DBEZOPIS    "Ukryj dni bez opisu"
#define DZOPIS      "Pokaz wszystkie dni"
#define WYCZ        "Wyczysc            "
#define OPCJ        "Opcje              "


#define MENU(x)   { \
                    WysrodkujTekst(x,"2-"EKS);\
                    fprintf(x,"1-"KAL"\n");\
                    WysrodkujTekst(x,"2-"EKS);\
                    fprintf(x, "2-"EKS"\n");\
                    WysrodkujTekst(x,"3-"POD);\
                    fprintf(x, "3-"POD"\n");\
                    WysrodkujTekst(x,"4-"DBEZOPIS);\
                    fprintf(x, "4-"DBEZOPIS"\n");\
                    WysrodkujTekst(x,"5-"DZOPIS);\
                    fprintf(x, "5-"DZOPIS"\n");\
                    WysrodkujTekst(x,"6-"WYCZ);\
                    fprintf(x, "6-"WYCZ"\n");\
                    WysrodkujTekst(x,"7-"OPCJ);\
                    fprintf(x, "7-"OPCJ"\n");\
}





void WysrodkujTekst(FILE *sciezka,char *tekst);
void dzien(FILE *sciezka,uint2 dzien);
void wypisz(wezel *wsk);
void menu();
uint2 zapisz(char* sciezkaZapisu, wezel* adres);
uint2 podglad(FILE *plik, wezel* adres);
uint2 kalendarz(wezel *wsk);
#endif // IN_OUT_H_INCLUDED
