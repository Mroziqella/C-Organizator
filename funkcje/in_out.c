#include "../header/in_out.h"


void WysrodkujTekst(FILE *sciezka,char *tekst)//wysrodkowuje tekst
{
    int i;
    for (i=0; i<(SZEROKOSC_KONSOLI-strlen(tekst))/2; i++)
        fprintf(sciezka," ");
}

void dzien(FILE *sciezka,uint2 dzien)
{
  if (dzien==0)
    {
        WysrodkujTekst(sciezka,SO);
        fprintf(sciezka,SO"\n");
    }
    else if(dzien==1)
    {
        WysrodkujTekst(sciezka,ND);
        fprintf(sciezka,ND"\n");
    }
    else if(dzien==2)
    {
        WysrodkujTekst(sciezka,PON);
        fprintf(sciezka,PON"\n");
    }
    else if(dzien==3)
    {
        WysrodkujTekst(sciezka,WT);
        fprintf(sciezka,WT"\n");
    }
    else if(dzien==4)
    {
        WysrodkujTekst(sciezka,SR);
        fprintf(sciezka,SR"\n");
    }
    else if(dzien==5)
    {
        WysrodkujTekst(sciezka,CZ);
        fprintf(sciezka,CZ"\n");
    }
    else if(dzien==6)
    {
        WysrodkujTekst(sciezka,PT);
        fprintf(sciezka,PT"\n");
    }
}

void wypisz(wezel *wsk)
{
    WysrodkujTekst(stdout,KALENDARZ);
    fprintf(stdout,KALENDARZ"\n\n\n\n\n");
    fprintf(stdout,"ENTER-zmiana opisu, a,s-poruszanie miedzy dniami,+/- -pokarz/ukryj dzien\n");
    if(wsk->wydarzenie==1)
            fprintf(stdout,"Status dnia: widzoczny\n");
    if(wsk->wydarzenie==0)
            fprintf(stdout,"Status dnia: ukryty\n");
    fprintf(stdout,"--------------------------------------------------------------------------------\n");
    WysrodkujTekst(stdout,"dd-mm-rrrr");
    fprintf(stdout,"%i-%i-%i\n",wsk->dzien,wsk->miesiac+1,wsk->rok);
    dzien(stdout,wsk->dzienTyg);
    fprintf(stdout,"\n\n\nOpis : \n");
    fprintf(stdout,"%s",wsk->tekst);
}


uint2 zapisz(char  *sciezkaZapisu, wezel *adres)
{
    FILE *plik;
    if ((plik=fopen(sciezkaZapisu,"w"))==NULL)
    {
        fprintf(plik,"Nie moge otworzyc pliku!\n");
        return 0;
    }
    while(adres!=NULL)
    {
        if (adres->wydarzenie==1)
        {
            WysrodkujTekst(plik,"dd-mm-rrrr");
            fprintf(plik,"%i-%i-%i\n",adres->dzien,adres->miesiac+1,adres->rok);
            dzien(plik,adres->dzienTyg);
            fprintf(plik,"Opis: %s\n",adres->tekst);
            fprintf(plik,"--------------------------------------------------------------\n\n");
        }
        adres=adres->nast;
    }
    if (fclose(plik))
    {
        fprintf(plik,"Nie moge zamknac pliku!\n");
        return 0;
    }
    return 1;

}

uint2 podglad(FILE *plik, wezel* adres)
{
    while(adres!=NULL)
    {
        if (adres->wydarzenie==1)
        {
            WysrodkujTekst(plik,"dd-mm-rrrr");
            fprintf(plik,"%i-%i-%i\n",adres->dzien,adres->miesiac+1,adres->rok);
            dzien(plik,adres->dzienTyg);
            fprintf(plik,"Opis: %s\n",adres->tekst);
            fprintf(plik,"--------------------------------------------------------------\n\n");
        }
        adres=adres->nast;
    }
    return 1;
}

void opcje(char *sciezka)
{
    char znak='0';
    uint4 i=0;
    while(znak!=ESC)
    {
            fprintf(stdout,"Sciezka do eksportowania: %s\n\n\n\n",sciezka);
            WysrodkujTekst(stdout,"1-Zmien sciezke eksportu pliku");
            fprintf(stdout,"1-Zmien sciezke eksportu pliku\n");
            znak=getch();
            switch(znak)
            {
                case '1':
                        {
                            fprintf(stdout,"Podaj nowa sciezke eksportu do pliku:");
                            fgets(sciezka,ROZMIAR_SCIEZKI,stdin);
                            for(i=0;sciezka[i]!='\0';i++);
                            sciezka[i-1]='\0';
                            system("cls");
                            break;
                        }
                default : continue;
            }
    }
}

void generuj(wezel *wsk,uint4 dni)
{
    uint4 i;
    for (i=0;i<dni;i++)
     wsk=kalendarzNast(wsk);
}

void menu()
{
    wezel lista,*wsk;
    char znak='0',sciezka[ROZMIAR_SCIEZKI]="plik1.txt";
    time_t czas;
    time(&czas);
    wsk=&lista;
    listaStart(wsk);
    MENU(stdout);
    while((znak=getch())!=ESC)
    {
        switch (znak)
        {
            case '1':
                    {
                        system("CLS");
                        kalendarz(wsk);
                        break;
                    }
            case '2':
                    {
                        if (zapisz(sciezka,wsk)==1)
                        {
                            fprintf(stdout,"\nEksportowanie pliku zakonczylo sie pomyslnie\n");
                        }
                        else
                        {
                            fprintf(stdout,"\nEksportowanie pliku - Blad!!!\n");
                        }
                        system("pause");
                        system("CLS");
                        break;
                    }
            case '3':
                    {
                        fprintf(stdout,"\n\n\n\n");
                        podglad(stdout,wsk);
                        system("pause");
                        system("CLS");
                        break;
                    }
            case '4':
                    {
                        ukryjBezOpisu(wsk);// ukrywa wezly bez opisu w podgladzie
                        fprintf(stdout,"\n\n\n");
                        WysrodkujTekst(stdout,"Ukryto");
                        fprintf(stdout,"Ukryto\n");
                        system("pause");
                        system("CLS");
                        break;
                    }
            case '5':
                    {
                        pokazBezOpisu(wsk);//pokazuje wezly bez opisu w podgladzie
                        fprintf(stdout,"\n\n\n");
                        WysrodkujTekst(stdout,"Pokazano");
                        fprintf(stdout,"Pokazano\n");
                        system("pause");
                        system("CLS");
                        break;
                    }
            case '6':
                    {
                        wyczyscliste(wsk);
                        pokazBezOpisu(wsk);
                        fprintf(stdout,"\n\n\n");
                        WysrodkujTekst(stdout,"Lista zostala wyczyszczona");
                        fprintf(stdout,"Lista zostala wyczyszczona!!!\n");
                        system("pause");
                        system("CLS");
                        break;
                    }
            case '7':
                    {
                        system("cls");
                        opcje(sciezka);
                        system("cls");
                        break;
                    }

            default:{
                    continue;
                    }
        }
        MENU(stdout);

    }
    wyczyscliste(wsk);
}



uint2 kalendarz(wezel *wsk)
{
    char znak='0';
     while(1)
    {
        switch(znak)
        {
        case 'd':
                {
                wsk=kalendarzNast(wsk);
                break;
                }
        case 'a':
                {
                wsk=kalendarzPoprz(wsk);
                break;
                }
        case 'e':
                {
                wsk=kalendarzNastZOpis(wsk);
                break;
                }
        case 'q':
                {
                wsk=kalendarzPoprzZOpis(wsk);
                break;
                }
        case '+':
                {
                wsk->wydarzenie=1;
                break;
                }
        case '-':
                {
                wsk->wydarzenie=0;
                break;
                }
        case ENTER:
                {
                wsk->tekst[0]='\0';
                wypisz(wsk);
                fprintf(stdout,"Nowy opis:\n");
                fgets(wsk->tekst,DLUGOSC_TEKSTU,stdin);
                if (wsk->tekst[0]==10)
                    wsk->tekst[0]='\0';
                system("CLS");
                break;
                }
        case ESC:
                {
                return 1;
                }
        }
        wypisz(wsk);
        znak=getch();
        system("cls");

    }
}

