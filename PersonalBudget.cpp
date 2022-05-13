#include "PersonalBudget.h"

void PersonalBudget::userRegistration(){
    userManager.userRegistration();
}

void PersonalBudget::loadDataIntoAVector(){
    userManager.loadDataIntoAVector();
}

int PersonalBudget::userLoggIn(){
    userManager.userLoggIn();
    if (userManager.isTheUserLoggedIn()){
        addManager = new AddManager(userManager.getTheLoggedInUserID());
    }
}

void PersonalBudget::changeOfTheLoggedInUserPassword(int loggedInUserID){
    userManager.changeOfTheLoggedInUserPassword(loggedInUserID);
}

int PersonalBudget::getTheLoggedInUserID(){
    userManager.getTheLoggedInUserID();
}

int PersonalBudget::addIncome(){
    addManager->addIncome();
    return 0;
}
