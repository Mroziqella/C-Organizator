/**
******************* Organizator luty 2015 *********************
********************** Autor: Mróz Kamil **********************
****************** e-mail: mroziqella@o2.pl *******************
************ Github:https://github.com/Mroziqella *************
**/

#include "header/mysys.h"
#include "header/teksty.h"
#include "header/operacje.h"
#include "header/in_out.h"
#include "header/lista.h"


int main()
{

///////////////////////////////////////////////////////////////////////

    WysrodkujTekst(stdout,POWITALNY);
    fprintf(stdout,POWITALNY);
    fprintf(stdout,"\n\n\n");
    WysrodkujTekst(stdout,INFO);
    fprintf(stdout,INFO);
    fprintf(stdout,"\n\n\n");
    WysrodkujTekst(stdout,KONTYNULUJ);
    fprintf(stdout,KONTYNULUJ);
    fprintf(stdout,"\n\n\n");
    getchar();
    system("cls");
    menu();

    return 0;
}
