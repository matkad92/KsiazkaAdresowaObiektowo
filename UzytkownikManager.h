#ifndef UZYTKOWNIKMANAGER_H
#define UZYTKOWNIKMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include  <sstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikManager
{
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin( string login);
    PlikZUzytkownikami plikZUzytkownikami;


public:

    UzytkownikManager (string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami), idZalogowanegoUzytkownika(0)
    {
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    }
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void ustawIdZalogowanegoUzytkownika(int noweId);
    int pobierzIdZalogowanegoUzytkownika();
    bool czyUzytkownikJestZalogowany();
    void wylogowanieUzytkownika();


};

#endif
