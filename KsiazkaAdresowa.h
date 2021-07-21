#include <iostream>

#include "UzytkownikManager.h"
#include "AdresatManager.h"

using namespace std;

class KsiazkaAdresowa
{
private :

    UzytkownikManager uzytkownikManager;
    AdresatManager adresatManager;
    int idZalogowanegoUzytkownika;

public :
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami);
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogujUzytkownika ()
    {
        idZalogowanegoUzytkownika = 0;
        //~adresatManager();   Wylogowanie uzytkownika
    }

    void dodajAdresata();
    void wyswietlWszystkichAdresatow();



};
