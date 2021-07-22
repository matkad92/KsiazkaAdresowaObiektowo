#include <iostream>

#include "UzytkownikManager.h"
#include "AdresatManager.h"

using namespace std;

class KsiazkaAdresowa
{
private :

    UzytkownikManager uzytkownikManager;
    AdresatManager *adresatManager;//Utworzenie wskaznika pozwala pozniej stworzyc obiekt danej klasy, jak juz bedzie znane id Uzytkownika
    int idZalogowanegoUzytkownika;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

public :
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami);
    ~KsiazkaAdresowa()
    {
        delete adresatManager;//Trzeba utworzyc destruktor korzystajac ze wskaznikow
        adresatManager = NULL;
    }
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogujUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    bool czyUzytkownikJestZalogowany();
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();

};
