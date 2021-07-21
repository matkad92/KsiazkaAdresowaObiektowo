#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{

    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt", "Adresaci.txt");

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    ksiazkaAdresowa.logowanieUzytkownika();

    ksiazkaAdresowa.dodajAdresata();

    ksiazkaAdresowa.wyswietlWszystkichAdresatow();

    ksiazkaAdresowa.wylogujUzytkownika();


    return 0;
}
