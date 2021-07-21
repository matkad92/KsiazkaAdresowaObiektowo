#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{

    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt");
    //cout << ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika()<<endl;
    cout << "LOGOWANIE"<<endl;
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.dodajAdresata();

    cout << "Wyswietlenie wszystkich adresatow"<<endl;
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();


    //cout << "przed zmiana hasla"<<endl<<endl<<endl;
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    //cout << endl<<endl<<endl<<"po zmiana hasla"<<endl<<endl<<endl;
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    //cout << ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika()<<endl;
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();


    return 0;
}
