#ifndef ADDMANAGER_H
#define ADDMANAGER_H
#include <iostream>
#include <vector>
#include "Incomes.h"
#include <ctime>
#include <conio.h>
#include "AuxiliaryMethods.h"

using namespace std;

class AddManager{
//    Incomes incomes;
    vector <Incomes> incomesVec;
//    vector <Expenses> expensesVec;


public:
    int addIncome();
    string getSystemDate();
//    string enterDateYYYYMMDD();
    int addExpense();
    void wyswietl();
    Incomes writeNewThings();
    string addZeroBeforeMonth(string variable, int monthToday);
    string addZeroBeforeDay(string variable, int dayToday);
    string getYearMonthDay(string date);
    string checkTheComma(string amountText);
};

#endif
