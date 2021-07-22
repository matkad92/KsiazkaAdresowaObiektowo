#include "AdresatManager.h"


void AdresatManager::dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
    {
        cout << "Nowy adresat zostal dodany" << endl;
    }
    else
    {
        cout << "Blad. Nie udalo sie dodac adresata do pliku" << endl;
        system("pause");
    }

}

Adresat AdresatManager::podajDaneNowegoAdresata()
{
    Adresat adresat;

    adresat.ustawId((plikZAdresatami.pobierzIdOstatniegoAdresata()+1));
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze::wczytajLinie());
    adresat.ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());
    adresat.ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}

void AdresatManager::wyswietlWszystkichAdresatow()
{
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatManager::wyszukajAdresatowPoImieniu()
{
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzImie() == imiePoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatManager::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow)
{
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}

void AdresatManager::wyszukajAdresatowPoNazwisku()
{
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
         wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatManager::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu()<< endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres()<< endl;
}

void  AdresatManager::usunAdresata()
{

    int idUsuwanegoAdresata, iloscZnalezionychKontaktow;
    char potwierdzenieUsuniecia;

    system ("cls");
    cout << "Podaj id adresata, ktorego chcesz usunac:" << endl;
    cin >> idUsuwanegoAdresata;
    system ("cls");
    for (vector<Adresat>::iterator itr = adresaci.begin(), koniec = adresaci.end(); itr != koniec; ++itr)
    {
        if (itr -> pobierzId() == idUsuwanegoAdresata )
        {
            cout << "ID kontaktu: " << itr -> pobierzId()  << endl;
            cout << "Imie: " << itr -> pobierzImie() << endl;
            cout << "Nazwisko: " << itr -> pobierzNazwisko() << endl;
            cout << "Numer telefonu: " <<  itr -> pobierzNumerTelefonu() << endl;
            cout << "Adres zamieszkania: " <<  itr -> pobierzAdres() << endl;
            cout << "Adres e-mail: " <<  itr -> pobierzEmail()<< endl << endl;

            cout << "Prosze o potwierdzenie usuniecia poprzez wcisniecie klawisza  -  t" << endl;
            cin >> potwierdzenieUsuniecia;


            if (potwierdzenieUsuniecia == 't')
            {
                cout << endl;
                adresaci.erase(itr);

                plikZAdresatami.wyczyscIzapiszWszystkieKontaktyDoUsuwania(idUsuwanegoAdresata);

                cout << "Adresat zostal poprawnie usuniety.";
                getch();
            }

            else
            {
                cout << "Adresat nie zostal usuniety";
                getch();
                return;
            }
            iloscZnalezionychKontaktow++;
        }
    }


    if (iloscZnalezionychKontaktow == 0)
    {
        cout << "Nie znaleziono adresata o podanym numerze id.";
        getch();
        return;
    }
}

void AdresatManager::edytujAdresata()
{
    int idDoEdycji, iloscZnalezionychKontaktow;
    char wybor;
    iloscZnalezionychKontaktow = 0;
    system ("cls");
    cout << "Podaj id adresata, ktorego dane chcesz edytowac:" << endl;
    cin >> idDoEdycji;
    system ("cls");
    for (vector<Adresat>::iterator itr = adresaci.begin(), koniec = adresaci.end(); itr != koniec; ++itr)
    {
        if (itr -> pobierzId() == idDoEdycji)
        {
            cout << "ID kontaktu: " << itr -> pobierzId()  << endl;
            cout << "Imie: " << itr -> pobierzImie() << endl;
            cout << "Nazwisko: " << itr -> pobierzNazwisko() << endl;
            cout << "Numer telefonu: " <<  itr -> pobierzNumerTelefonu() << endl;
            cout << "Adres zamieszkania: " <<  itr -> pobierzAdres() << endl;
            cout << "Adres e-mail: " <<  itr -> pobierzEmail()<< endl << endl;

            cout << "Wybierz numer:" << endl;

            cout << " 1. Edytuj imie" << endl;
            cout << " 2. Edytuj nazwisko" << endl;
            cout << " 3. Edytuj numer telefonu" << endl;
            cout << " 4. Edytuj email" << endl;
            cout << " 5. Edytuj adres" << endl;
            cout << " 6. powrot do menu" << endl;

            cin >> wybor;

            if (wybor == '1')
            {
                cout << endl;
                edytujImie(idDoEdycji);
            }

            if (wybor == '2')
            {
                cout << endl;
                edytujNazwisko(idDoEdycji);
            }

            if (wybor == '3')
            {
                cout << endl;
                edytujNumerTel(idDoEdycji);
            }

            if (wybor == '4')
            {
                cout << endl;
                edytujEmail(idDoEdycji);
            }

            if (wybor == '5')
            {
                cout << endl;
                edytujAdres(idDoEdycji);
            }

            if (wybor == '6')
            {
                return;
            }

            iloscZnalezionychKontaktow++;
        }
    }

    if (iloscZnalezionychKontaktow == 0)
    {
        cout << "Nie znaleziono kontaktu o podanym numerze id.";
        getch();
        return;
    }

    return;
}

void  AdresatManager::edytujImie (int idDoEdycji)
{
    system ("cls");
    string noweImie;
    cout << "Podaj nowe imie:" << endl;

    cin >> noweImie;

    for (vector<Adresat>::iterator itr = adresaci.begin(), koniec = adresaci.end(); itr != koniec; ++itr)
    {
        if (itr -> pobierzId() == idDoEdycji)
        {
            itr -> ustawImie(noweImie);
        }
    }

    plikZAdresatami.wyczyscIzapiszWszystkieKontakty(adresaci, idDoEdycji);

    cout << "Kontakt zostal aktualizowany";
    getch();

    return;
}

void  AdresatManager::edytujNazwisko (int idDoEdycji)
{
    system ("cls");
    string noweNazwisko;
    cout << "Podaj nowe nazwisko:" << endl;

    cin >> noweNazwisko;

    for (vector<Adresat>::iterator itr = adresaci.begin(), koniec = adresaci.end(); itr != koniec; ++itr)
    {
        if (itr -> pobierzId() == idDoEdycji)
        {
            itr -> ustawNazwisko(noweNazwisko);
        }
    }

    plikZAdresatami.wyczyscIzapiszWszystkieKontakty(adresaci, idDoEdycji);

    cout << "Kontakt zostal aktualizowany";
    getch();

    return;
}


void  AdresatManager::edytujNumerTel (int idDoEdycji)
{
    system ("cls");
    string noweNumer;
    cout << "Podaj nowy numer telefonu:" << endl;

    cin >> noweNumer;

    for (vector<Adresat>::iterator itr = adresaci.begin(), koniec = adresaci.end(); itr != koniec; ++itr)
    {
        if (itr -> pobierzId() == idDoEdycji)
        {
            itr -> ustawNumerTelefonu(noweNumer);
        }
    }

    plikZAdresatami.wyczyscIzapiszWszystkieKontakty(adresaci, idDoEdycji);

    cout << "Kontakt zostal aktualizowany";
    getch();

    return;
}

void  AdresatManager::edytujEmail (int idDoEdycji)
{
    system ("cls");
    string nowyEmail;
    cout << "Podaj nowy e-mail:" << endl;

    cin >> nowyEmail;

    for (vector<Adresat>::iterator itr = adresaci.begin(), koniec = adresaci.end(); itr != koniec; ++itr)
    {
        if (itr -> pobierzId() == idDoEdycji)
        {
            itr -> ustawEmail(nowyEmail);
        }
    }

    plikZAdresatami.wyczyscIzapiszWszystkieKontakty(adresaci, idDoEdycji);

    cout << "Kontakt zostal aktualizowany";
    getch();

    return;
}


void  AdresatManager::edytujAdres (int idDoEdycji)
{
    system ("cls");
    string nowyAdres;
    cout << "Podaj nowy adres zamieszkania:" << endl;

    cin >> nowyAdres;

    for (vector<Adresat>::iterator itr = adresaci.begin(), koniec = adresaci.end(); itr != koniec; ++itr)
    {
        if (itr -> pobierzId() == idDoEdycji)
        {
            itr -> ustawAdres(nowyAdres);
        }
    }

    plikZAdresatami.wyczyscIzapiszWszystkieKontakty(adresaci, idDoEdycji);

    cout << "Kontakt zostal aktualizowany";
    getch();

    return;
}
