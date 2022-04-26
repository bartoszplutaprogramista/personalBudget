#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>
#include "UserManager.h"
#include "User.h"
#include "Markup.h"

using namespace std;

//UserManager userManager;

class PersonalBudget{
    UserManager userManager;
public:
    void loadDataIntoAVector();
    void userRegistration();

/*
    changeOfTheLoggedInUserPassword();
    userLoggIn();
    addIncome();
    addExpense();
    getTheLoggedInUserID();
    setTheLoggedInUserID(int id);
    loggOutOfTheUser();
    displayCurrentMonthBalance();
    displayTheBalanceForThePreviousMonth();
    displayTheBalanceForTheSelectedPeriod(); */
};

#endif
