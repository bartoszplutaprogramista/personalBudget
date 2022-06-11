#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "Incomes.h"
#include "AddManager.h"
#include "AuxiliaryMethods.h"
#include "Date.h"
#include <iomanip>

using namespace std;

struct Comparison{
    inline bool operator() (Incomes& struct1, Incomes& struct2)
    {
        return (struct1.getDate() < struct2.getDate());
    }
};

struct ComparisonExpenses{
    inline bool operator() (Expenses& structExpenses1, Expenses& structExpenses2)
    {
        return (structExpenses1.getDate() < structExpenses2.getDate());
    }
};

class BalanceManager{
    vector <Incomes> incomesVecBalance;
    vector <Expenses> expensesVecBalance;

public:
    bool checkJanuary(string help);
    void displayTheBalanceSheetForThePreviousMonth(vector <Incomes> incomesVecBalance, vector <Expenses> expensesVecBalance, char choiceMenu);
    float displayIncomesForTheCurrentOrPreviousMonth(vector <Incomes> incomesVecBalance, int deletingInt, char choiceMenu);
    float displayExpensesForTheCurrentOrPreviousMonth(vector <Expenses> expensesVecBalance, int deletingInt, char choiceMenu);
    void displayBalanceSheetForTheCurrentMonth(vector <Incomes> incomesVecBalance, vector <Expenses> expensesVecBalance, char choiceMenu);
    void displayTheBalanceForTheSelectedPeriod(vector <Incomes> incomesVecBalance, vector <Expenses> expensesVecBalance);
    float showTheBalanceSheetForTheSelectedPeriodIncomes(vector <Incomes> incomesVecBalance, int firstDateInt, int secondDateInt);
    float showTheBalanceSheetForTheSelectedPeriodExpenses(vector <Expenses> expensesVecBalance, int firstDateInt, int secondDateInt);

};

#endif


