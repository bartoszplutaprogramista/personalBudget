#ifndef ADDMANAGER_H
#define ADDMANAGER_H
#include <iostream>
#include <vector>
#include "Incomes.h"
#include "Expenses.h"
#include <ctime>
#include <conio.h>
#include "AuxiliaryMethods.h"
#include "FileXMLIncomes.h"
#include "FileXMLExpenses.h"
#include "UserManager.h"

using namespace std;

class AddManager{
    const int LOGGED_IN_USER_ID;
    vector <Incomes> incomesVec;
    vector <Expenses> expensesVec;
    int incomeID;
    int expenseID;


public:
    AddManager(int loggedInUserID)
    : LOGGED_IN_USER_ID(loggedInUserID){
        incomeID = 0;
        expenseID = 0;
    };
    int addIncome();
    int addExpense();
    void wyswietl();
    Incomes writeNewThings();
    Incomes writeToday();
    Incomes writeWithAnotherDate(string date);
    Expenses writeNewThingsOfExpenses();
    int getIDOfNewUserOfExpenses();
    Expenses writeWithAnotherDateOfExpenses(string date);
    Expenses writeTodayExpenses();
    string getYearMonthDay(string date);
    string checkTheComma(string amountText);
    void loadDataOfIncomesIntoAVector();
    void loadDataOfExpensesIntoAVector();
    int getIDOfNewUser();

    vector <Incomes> getIncomesVec();
    vector <Expenses> getExpensesVec();
    int getLOGGED_IN_USER_ID();

};

#endif
