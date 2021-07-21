#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H


#include <iostream>
#include <vector>
#include <fstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami
{
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    int idOstatniegoAdresata;

    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    bool czyPlikJestPusty(fstream &plikTekstowy);

public:
    PlikZAdresatami(string przeslanaNazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(przeslanaNazwaPlikuZAdresatami)
    {
        idOstatniegoAdresata = 0;
    }
    void dopiszAdresataDoPliku();
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku (int idZalogowanegoUzytkownika);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    bool dopiszAdresataDoPliku(Adresat adresat);
    int pobierzIdOstatniegoAdresata();

};

#endif
