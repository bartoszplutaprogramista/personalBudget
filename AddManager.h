#ifndef ADDMANAGER_H
#define ADDMANAGER_H
#include <iostream>
#include <vector>
#include "Incomes.h"
#include <ctime>
#include <conio.h>
#include "AuxiliaryMethods.h"
#include "FileXMLIncomes.h"
#include "UserManager.h"
//#include "PersonalBudget.h"

using namespace std;

class AddManager{
//    Incomes incomes;
    const int LOGGED_IN_USER_ID;
    vector <Incomes> incomesVec;
    int incomeID;
//    vector <Expenses> expensesVec;


public:
    AddManager(int loggedInUserID)
    : LOGGED_IN_USER_ID(loggedInUserID){
        incomeID = 0;
    };
    int addIncome();
    string getSystemDate();
//    string enterDateYYYYMMDD();
    int addExpense();
    void wyswietl();
    Incomes writeNewThings();
    Incomes writeToday();
    Incomes writeWithAnotherDate(string date);
    string addZeroBeforeMonth(string variable, int monthToday);
    string addZeroBeforeDay(string variable, int dayToday);
    string getYearMonthDay(string date);
    string checkTheComma(string amountText);
};

#endif
