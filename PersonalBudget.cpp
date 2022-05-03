#include "PersonalBudget.h"

void PersonalBudget::userRegistration(){
    userManager.userRegistration();
}

void PersonalBudget::loadDataIntoAVector(){
    userManager.loadDataIntoAVector();
}

int PersonalBudget::userLoggIn(){
    userManager.userLoggIn();


//    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()){
//        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
//    }
    return 0;
}

void PersonalBudget::changeOfTheLoggedInUserPassword(int loggedInUserID){
    userManager.changeOfTheLoggedInUserPassword(loggedInUserID);
}

int PersonalBudget::getTheLoggedInUserID(){
    userManager.getTheLoggedInUserID();
    return userManager.getTheLoggedInUserID();
}

int PersonalBudget::addIncome(){
    addManager.addIncome();
    return 0;
}

/*
void PersonalBudget::loggOutOfTheUser(){
    userManager.loggOutOfTheUser();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
    cout << "Wylogowano poprawnie" << endl;
}
*/
