#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikManager(nazwaPlikuZUzytkownikami)
{
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

/* KsiazkaAdresowa::wczytajUzytkownikowZPliku()
{
    uzytkownikManager.wczytajUzytkownikowZPliku();
}*/

void KsiazkaAdresowa::logowanieUzytkownika()
{
    idZalogowanegoUzytkownika = uzytkownikManager.logowanieUzytkownika();
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}
