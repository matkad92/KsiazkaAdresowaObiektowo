#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat
{
    int id;
    int idUzytkownika;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string email;
    string adres;

public :
    //Musza w konstruktorze zostac dodane wartosci domyslne jak uzywamy this!
    Adresat (int id=0, int ididUzytkownika=0, string imie="" ,string nazwisko="" ,string numerTelefonu="" ,string email="" ,string adres="" )
    {
        this->id = id; //Wskaznik this pozwala na bezposredni dostep do skladowych klasy i dzieki niemu nie musimy wymyslac innych nazwy, zeby nie przyslonily
        this->idUzytkownika = idUzytkownika;
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->numerTelefonu = numerTelefonu;
        this->email = email;
        this->adres = adres;



    }

    void ustawId(int noweId);
    void ustawIdUzytkownika(int noweIdUzytykownika);
    void ustawImie(string nowyImie);
    void ustawNazwisko(string noweNazwisko);
    void ustawNumerTelefonu(string nowyNumerTelefonu);
    void ustawEmail(string noweEmail);
    void ustawAdres(string nowyAdres);

    int pobierzId();
    int pobierzIdUzytkownika();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzNumerTelefonu();
    string pobierzEmail();
    string pobierzAdres();

};

#endif
