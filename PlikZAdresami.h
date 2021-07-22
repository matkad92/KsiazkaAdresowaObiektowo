#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H


#include <iostream>
#include <vector>
#include <fstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"


using namespace std;

class PlikZAdresatami : public PlikTekstowy
{
    int idOstatniegoAdresata;

    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);

public:
    PlikZAdresatami(string przeslanaNazwaPlikuZAdresatami) : PlikTekstowy(przeslanaNazwaPlikuZAdresatami)
    {
        idOstatniegoAdresata = 0;
    }
    void dopiszAdresataDoPliku();
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku (int idZalogowanegoUzytkownika);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    bool dopiszAdresataDoPliku(Adresat adresat);
    int pobierzIdOstatniegoAdresata();
    void  wyczyscIzapiszWszystkieKontaktyDoUsuwania(int idUsuwanegoAdresata);
    void wyczyscIzapiszWszystkieKontakty(vector <Adresat> &adresaci, int idDoEdycji);

};

#endif
