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

class BalanceManager{
    vector <Incomes> incomesVecBalance;

public:
//    BalanceManager(){
//        incomesVecBalance = addManager.getIncomesVec();
//    };
    void displayIncomesForTheCurrentMonth(vector <Incomes> incomesVecBalance);
    void displayBalanceSheetForTheCurrentMonth(vector <Incomes> incomesVecBalance, vector <Expenses> expensesVecBalance);
};

#endif


