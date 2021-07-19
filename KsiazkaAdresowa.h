#include <iostream>

#include "UzytkownikManager.h"

using namespace std;

class KsiazkaAdresowa
{
private :

    UzytkownikManager uzytkownikManager;

public :
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami);
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();

};
