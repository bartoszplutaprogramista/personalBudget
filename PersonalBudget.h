#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>
#include <conio.h>
#include "UserManager.h"
#include "User.h"
//#include "Incomes.h"
//#include "Expenses.h"
#include "AddManager.h"
#include "Markup.h"
#include "BalanceManager.h"

using namespace std;

//UserManager userManager;

class PersonalBudget{
    UserManager userManager;
    AddManager *addManager;
    vector <Incomes> incomesVecBalance;
    vector <Expenses> expensesVecBalance;
    BalanceManager balanceManager;
public:
    int addIncome();
    int addExpense();
    void loadDataIntoAVector();
    void userRegistration();
    int userLoggIn();
    void changeOfTheLoggedInUserPassword(int loggedInUserID);
    int getTheLoggedInUserID();
    void loggOutOfTheUser();
    void displayBalanceSheetForTheCurrentMonth(char choiceMenu);
    void displayTheBalanceSheetForThePreviousMonth(char choiceMenu);
    void displayTheBalanceForTheSelectedPeriod();
};

#endif
