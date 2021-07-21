#ifndef ADRESATMANAGER_H
#define ADRESATMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Adresat.h"
#include "PlikZAdresami.h"

using namespace std;

class AdresatManager
{
    int idZalogowanegoUzytkownika;
    static int idOstatniegoAdresata;/////Zainicjalizowac
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;


    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    void wyswietlDaneAdresata(Adresat adresat);

public :
    AdresatManager(int przeslaneIdZalogowanegoUzytkownika);
    int dodajAdresata(int przeslaneIdZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow(int przeslaneIdZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow();


};

#endif
