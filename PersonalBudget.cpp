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
        addManager->loadDataOfIncomesIntoAVector();
        addManager->loadDataOfExpensesIntoAVector();
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

int PersonalBudget::addExpense(){
    addManager->addExpense();
    return 0;
}

void PersonalBudget::loggOutOfTheUser(){
    userManager.loggOutOfTheUser();
    delete addManager;
    addManager = NULL;
    cout << "Wylogowano poprawnie" << endl;
    getch();
}

void PersonalBudget::displayBalanceSheetForTheCurrentMonth(){
    incomesVecBalance = addManager->getIncomesVec();
    balanceManager.displayBalanceSheetForTheCurrentMonth(incomesVecBalance);
}
