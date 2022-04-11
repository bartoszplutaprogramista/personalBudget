#include "PersonalBudget.h"


void PersonalBudget::loggOutOfTheUser(){
    userManager.loggOutOfTheUser();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
    cout << "Wylogowano poprawnie" << endl;
}
