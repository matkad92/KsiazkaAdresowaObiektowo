#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikManager(nazwaPlikuZUzytkownikami) {
    idZalogowanegoUzytkownika = 0;
    uzytkownikManager.wczytajUzytkownikowZPliku();
}

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
   uzytkownikManager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
   uzytkownikManager.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    idZalogowanegoUzytkownika = uzytkownikManager.logowanieUzytkownika();
    adresatManager.logowanieUzytkownika(idZalogowanegoUzytkownika);
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::dodajAdresata()
{
    adresatManager.dodajAdresata(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatManager.wyswietlWszystkichAdresatow();
}
