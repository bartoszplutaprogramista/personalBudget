#include "PersonalBudget.h"

void PersonalBudget::userRegistration(){
    userManager.userRegistration();
}

void PersonalBudget::loadDataIntoAVector(){
    userManager.loadDataIntoAVector();
}

/*
void PersonalBudget::loggOutOfTheUser(){
    userManager.loggOutOfTheUser();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
    cout << "Wylogowano poprawnie" << endl;
}
*/
