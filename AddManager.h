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
    void addIncome();
    string getSystemDate();
//    string enterDateYYYYMMDD();
    int addExpense();
    void wyswietl();
    Incomes writeNewThings(char choice);
    string addZeroBefore(string variable, int monthToday, int dayToday);
    string getYearMonthDay(string date);
    string checkTheComma(string amountText);
};

#endif
