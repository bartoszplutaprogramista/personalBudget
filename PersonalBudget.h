#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>
#include "UserManager.h"
#include "User.h"
#include "AddManager.h"
#include "Markup.h"

using namespace std;

//UserManager userManager;

class PersonalBudget{
    UserManager userManager;
    AddManager addManager;
public:
    int addIncome();
    void loadDataIntoAVector();
    void userRegistration();
    int userLoggIn();
    void changeOfTheLoggedInUserPassword(int loggedInUserID);
    int getTheLoggedInUserID();

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