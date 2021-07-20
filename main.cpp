#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{

    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt");
    cout << ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika()<<endl;
    cout << "LOGOWANIE"<<endl;
    ksiazkaAdresowa.logowanieUzytkownika();
    cout << ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika()<<endl;
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();


    return 0;
}
