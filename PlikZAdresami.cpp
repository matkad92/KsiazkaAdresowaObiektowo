#include "PlikZAdresami.h"

int PlikZAdresatami::pobierzIdOstatniegoAdresata()
{
    return idOstatniegoAdresata;
}

vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku (int idZalogowanegoUzytkownika)
{
    vector <Adresat> adresaci;
    Adresat adresat;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        plikTekstowy.close();
    }

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }

    return adresaci;
}
int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}


int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty() == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }

    return false;
}
string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

void  PlikZAdresatami::wyczyscIzapiszWszystkieKontaktyDoUsuwania(int idUsuwanegoAdresata)
{
    string linia;

    int idZPlikuInt;

    string imie, nazwisko, numerTelefonu, adresEmail, adresZamieszkania, idString, idUzytkownikaString, koniecLinii;

    fstream plikKontaktow;
    fstream plikKontaktowTymczasowych;
    string nazwaTymczasowegoPlikuZKontaktami = "Adresaci_tymczasowy.txt";
    plikKontaktow.open( pobierzNazwePliku().c_str(), ios::in );
    plikKontaktowTymczasowych.open( nazwaTymczasowegoPlikuZKontaktami.c_str(), ios::out | ios::app);


    while(!plikKontaktow.eof())
    {

        getline(plikKontaktow, idString, '|');
        if (idString.empty()) break;
        idZPlikuInt = atoi(idString.c_str());
        getline(plikKontaktow, idUzytkownikaString, '|');
        getline(plikKontaktow, imie, '|');
        getline(plikKontaktow, nazwisko, '|');
        getline(plikKontaktow, numerTelefonu, '|');
        getline(plikKontaktow, adresEmail, '|');
        getline(plikKontaktow, adresZamieszkania, '|');
        getline(plikKontaktow, koniecLinii);


        if (idZPlikuInt != idUsuwanegoAdresata)
        {
            plikKontaktowTymczasowych << idString << "|"<< idUzytkownikaString << "|" << imie << "|" << nazwisko << "|" << numerTelefonu << "|"
                    << adresEmail << "|" << adresZamieszkania << "|" << endl;
        }

    }

    plikKontaktow.close();
    plikKontaktowTymczasowych.close();

    remove( pobierzNazwePliku().c_str() );
    rename( nazwaTymczasowegoPlikuZKontaktami.c_str(), pobierzNazwePliku().c_str() );
}

void PlikZAdresatami::wyczyscIzapiszWszystkieKontakty(vector <Adresat> &adresaci, int idDoEdycji)
{
    string linia;
    int idZPlikuInt;

    string imie, nazwisko, numerTelefonu, adresEmail, adresZamieszkania, idString, idUzytkownikaString, koniecLinii;

    fstream plikKontaktow;
    fstream plikKontaktowTymczasowych;
    string nazwaTymczasowegoPlikuZKontaktami = "Adresaci_tymczasowy.txt";
    plikKontaktow.open( pobierzNazwePliku().c_str(), ios::in );
    plikKontaktowTymczasowych.open( nazwaTymczasowegoPlikuZKontaktami.c_str(), ios::out | ios::app);


    while(!plikKontaktow.eof())
    {

        getline(plikKontaktow, idString, '|');
        if (idString.empty()) break;
        idZPlikuInt = atoi(idString.c_str());
        getline(plikKontaktow, idUzytkownikaString, '|');
        getline(plikKontaktow, imie, '|');
        getline(plikKontaktow, nazwisko, '|');
        getline(plikKontaktow, numerTelefonu, '|');
        getline(plikKontaktow, adresEmail, '|');
        getline(plikKontaktow, adresZamieszkania, '|');
        getline(plikKontaktow, koniecLinii);


        if (idZPlikuInt != idDoEdycji)
        {
            plikKontaktowTymczasowych << idString << "|"<< idUzytkownikaString << "|" << imie << "|" << nazwisko << "|" << numerTelefonu << "|"
                    << adresEmail << "|" << adresZamieszkania << "|" << endl;
        }

        else if (idZPlikuInt == idDoEdycji)
        {
            for (vector<Adresat>::iterator itr = adresaci.begin(), koniec = adresaci.end(); itr != koniec; ++itr)
            {
                if (itr -> pobierzId() == idDoEdycji)
                {
                    plikKontaktowTymczasowych << itr -> pobierzId() << "|"<< itr -> pobierzIdUzytkownika() << "|" << itr -> pobierzImie() << "|"
                    << itr -> pobierzNazwisko() << "|" << itr -> pobierzNumerTelefonu() << "|"
                    << itr -> pobierzEmail() << "|" << itr -> pobierzAdres() << "|" << endl;
                }
            }

        }
    }

    plikKontaktow.close();
    plikKontaktowTymczasowych.close();

    remove( pobierzNazwePliku().c_str() );
    rename( nazwaTymczasowegoPlikuZKontaktami.c_str(), pobierzNazwePliku().c_str() );
}

