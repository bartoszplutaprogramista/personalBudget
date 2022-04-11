#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>

using namespace std;

class PersonalBudget{

public:
    changeOfTheLoggedInUserPassword();
    userRegistration();
    userLoggIn();
    addIncome();
    addExpense();
    getTheLoggedInUserID();
    setTheLoggedInUserID(int id);
    loggOutOfTheUser();
    displayCurrentMonthBalance();
    displayTheBalanceForThePreviousMonth();
    displayTheBalanceForTheSelectedPeriod();
};

#endif
