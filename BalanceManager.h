#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "Incomes.h"
#include "AddManager.h"
#include "AuxiliaryMethods.h"

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
//    BalanceManager(){
//        incomesVecBalance = addManager.getIncomesVec();
//    };
    float displayIncomesForTheCurrentMonth(vector <Incomes> incomesVecBalance, int deletingInt);
    float displayExpensesForTheCurrentMonth(vector <Expenses> expensesVecBalance, int deletingInt);
    void displayBalanceSheetForTheCurrentMonth(vector <Incomes> incomesVecBalance, vector <Expenses> expensesVecBalance);
};

#endif


