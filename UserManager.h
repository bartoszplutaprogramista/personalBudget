#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include "User.h"
#include "Markup.h"
#include "FileXMLUsers.h"


using namespace std;

class UserManager{
//    User user;
    FileXMLUsers fileXMLUsers;
    vector <User> users;
public:
    void userRegistration();
    User writeNewUserData();
    int getNewUserId();
    bool isThereALogin(string login);
/*
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
    bool czyUzytkownikJestZalogowany();
    int pobierzIdZalogowanegoUzytkownika();
    void ustawIdZalogowanegoUzytkownika(int id);
    void wylogowanieUzytkownika(); */

};

#endif
