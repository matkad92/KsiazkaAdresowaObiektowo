#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikManager(nazwaPlikuZUzytkownikami)
{
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
