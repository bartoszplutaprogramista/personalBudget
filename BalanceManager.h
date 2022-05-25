#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H
#include <iostream>
#include <vector>
#include "AddManager.h"

using namespace std;

class BalanceManager{
    vector <Incomes> incomesVecBalance;
public:
//    BalanceManager(){
//        incomesVecBalance = addManager.getIncomesVec();
//    };
    void displayBalanceSheetForTheCurrentMonth(vector <Incomes> incomesVecBalance);
};

#endif


