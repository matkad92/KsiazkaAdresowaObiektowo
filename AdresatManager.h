#ifndef ADRESATMANAGER_H
#define ADRESATMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <conio.h>
#include "Adresat.h"
#include "PlikZAdresami.h"

using namespace std;

class AdresatManager
{
    vector <Adresat> adresaci;
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    PlikZAdresatami plikZAdresatami;


    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);
    void  edytujImie (int idDoEdycji);
    void  edytujNazwisko (int idDoEdycji);
    void  edytujNumerTel (int idDoEdycji);
    void  edytujEmail (int idDoEdycji);
    void  edytujAdres (int idDoEdycji);


public :
    AdresatManager(string nazwaPlikuZAdresatami,int idZalogowanegoUzytkownika)
        : plikZAdresatami(nazwaPlikuZAdresatami),ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    }
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void logowanieUzytkownika(int przeslaneIdZalogowanegoUzytkownika);
    void wczytajAdresatowZalogowanegoUzytkownika(int przeslaneIdZalogowanegoUzytkownika);

    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    void usunAdresata();
    void edytujAdresata();


};

#endif
