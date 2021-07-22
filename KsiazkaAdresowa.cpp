#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
: uzytkownikManager(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
{
    idZalogowanegoUzytkownika = 0;
    adresatManager = NULL; //trzeba od razu w konstruktorze na null ustawiac
}

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
   uzytkownikManager.rejestracjaUzytkownika();
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
    if (uzytkownikManager.pobierzIdZalogowanegoUzytkownika() == 0) return true;
    else return false;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}
char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
   uzytkownikManager.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikManager.logowanieUzytkownika();
    if (uzytkownikManager.czyUzytkownikJestZalogowany())
    {
       adresatManager = new AdresatManager(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
    }
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika()
{
    idZalogowanegoUzytkownika = uzytkownikManager.pobierzIdZalogowanegoUzytkownika();
    return idZalogowanegoUzytkownika;
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata()
{
    if (uzytkownikManager.czyUzytkownikJestZalogowany())
    {
        adresatManager->dodajAdresata(); //Trzeba uzyc -> bo pracujemy na wskaznikach!
    }
    else
    {
        cout << "Aby dodac adresata, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::wylogujUzytkownika()
{
    uzytkownikManager.wylogowanieUzytkownika();
    delete adresatManager; //Wszystkie zmiennie w obiekcie sa usuwane przez kompilator, my musimy usunac tylko wskaznik
    adresatManager = NULL;
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    if (uzytkownikManager.czyUzytkownikJestZalogowany())
    {
        adresatManager->wyswietlWszystkichAdresatow(); //Trzeba uzyc -> bo pracujemy na wskaznikach!
    }
    else
    {
        cout << "Aby wyswietlac adresatow, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }

}

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu()
{
    if (uzytkownikManager.czyUzytkownikJestZalogowany())
    {
        adresatManager->wyszukajAdresatowPoImieniu(); //Trzeba uzyc -> bo pracujemy na wskaznikach!
    }
    else
    {
        cout << "Aby wyswietlac adresatow, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }

}
void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku()
{
    if (uzytkownikManager.czyUzytkownikJestZalogowany())
    {
        adresatManager->wyszukajAdresatowPoNazwisku();
    }
    else
    {
        cout << "Aby wyswietlac adresatow, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }

}

void KsiazkaAdresowa::usunAdresata()
{
    if (uzytkownikManager.czyUzytkownikJestZalogowany())
    {
        adresatManager->usunAdresata();
    }
    else
    {
        cout << "Nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::edytujAdresata()
{
    if (uzytkownikManager.czyUzytkownikJestZalogowany())
    {
        adresatManager->edytujAdresata();
    }
    else
    {
        cout << "Nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}
