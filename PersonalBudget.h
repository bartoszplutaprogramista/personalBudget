#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>
#include <conio.h>
#include "UserManager.h"
#include "User.h"
#include "AddManager.h"
#include "Markup.h"

using namespace std;

//UserManager userManager;

class PersonalBudget{
    UserManager userManager;
    AddManager *addManager;
public:
    int addIncome();
    int addExpense();
    void loadDataIntoAVector();
    void userRegistration();
    int userLoggIn();
    void changeOfTheLoggedInUserPassword(int loggedInUserID);
    int getTheLoggedInUserID();
    void loggOutOfTheUser();
};

#endif
