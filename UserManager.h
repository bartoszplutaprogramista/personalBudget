#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>

using namespace std;

class User{

public:
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
    bool czyUzytkownikJestZalogowany();
    int pobierzIdZalogowanegoUzytkownika();
    void ustawIdZalogowanegoUzytkownika(int id);
    void wylogowanieUzytkownika();

};

#endif
