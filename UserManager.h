#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include <conio.h>
#include "User.h"
#include "Markup.h"
#include "FileXMLUsers.h"
#include "AuxiliaryMethods.h"


using namespace std;

class UserManager{
//    User user;
    CMarkup xml;
    FileXMLUsers fileXMLUsers;
    int loggedInUserID;
    vector <User> users;
public:
    void loadDataIntoAVector();
    void userRegistration();
    User writeNewUserData();
    int getNewUserId();
    bool isThereALogin(string login);
    int userLoggIn();
    void changeOfTheLoggedInUserPassword(int loggedInUserID);
    int getTheLoggedInUserID();
/*
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
    bool czyUzytkownikJestZalogowany();
    int pobierzIdZalogowanegoUzytkownika();
    void ustawIdZalogowanegoUzytkownika(int id);
    void wylogowanieUzytkownika(); */

};

#endif
