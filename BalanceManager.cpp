#include "BalanceManager.h"

void BalanceManager::displayIncomesForTheCurrentMonth(vector <Incomes> incomesVecBalance){
    string date="", deltingString="", dateFromIncomesVec="", dateFromIncomesVecDeleted="";
    int dateInt = 0, deletingInt = 0, dateIntFromIncomesVecDeleted = 0;

    date = AuxiliaryMethods::getSystemDate();
    deltingString = AuxiliaryMethods::deleteTheLastTwoDigits(date);
    deletingInt = AuxiliaryMethods::convertStringToInt(deltingString);

    dateInt = AuxiliaryMethods::convertStringToInt(date);

    cout << "TWOJE PRZYCHODY Z BIEZACEGO MIESIACA: " << endl;

    sort(incomesVecBalance.begin(), incomesVecBalance.end(), Comparison());

    for (int i=0; i<incomesVecBalance.size(); i++){
        dateFromIncomesVec = AuxiliaryMethods::convertIntToString(incomesVecBalance[i].getDate());
        dateFromIncomesVecDeleted = AuxiliaryMethods::deleteTheLastTwoDigits(dateFromIncomesVec);
        dateIntFromIncomesVecDeleted = AuxiliaryMethods::convertStringToInt(dateFromIncomesVecDeleted);
        if (dateIntFromIncomesVecDeleted == deletingInt){
            cout << "Data: " << incomesVecBalance[i].getDate() << endl;
            cout << "Przychod:  " << incomesVecBalance[i].getItem() << endl;
            cout << "Kwota: " << incomesVecBalance[i].getAmount() << endl;
        }
    }
    getch();
}

/*
void BalanceManager::displayExpensesForTheCurrentMonth(vector <Incomes> expensesVecBalance){
    string date="", deltingString="", dateFromIncomesVec="", dateFromIncomesVecDeleted="";
    int dateInt = 0, deletingInt = 0, dateIntFromIncomesVecDeleted = 0;

    date = AuxiliaryMethods::getSystemDate();
    deltingString = AuxiliaryMethods::deleteTheLastTwoDigits(date);
    deletingInt = AuxiliaryMethods::convertStringToInt(deltingString);

    dateInt = AuxiliaryMethods::convertStringToInt(date);

    cout << "TWOJE PRZYCHODY Z BIEZACEGO MIESIACA: " << endl;

    sort(incomesVecBalance.begin(), incomesVecBalance.end(), Comparison());

    for (int i=0; i<incomesVecBalance.size(); i++){
        dateFromIncomesVec = AuxiliaryMethods::convertIntToString(incomesVecBalance[i].getDate());
        dateFromIncomesVecDeleted = AuxiliaryMethods::deleteTheLastTwoDigits(dateFromIncomesVec);
        dateIntFromIncomesVecDeleted = AuxiliaryMethods::convertStringToInt(dateFromIncomesVecDeleted);
        if (dateIntFromIncomesVecDeleted == deletingInt){
            cout << "Data: " << incomesVecBalance[i].getDate() << endl;
            cout << "Przychod:  " << incomesVecBalance[i].getItem() << endl;
            cout << "Kwota: " << incomesVecBalance[i].getAmount() << endl;
        }
    }
    getch();
} */

void BalanceManager::displayBalanceSheetForTheCurrentMonth(vector <Incomes> incomesVecBalance, vector <Expenses> expensesVecBalance){
    system("cls");
    displayIncomesForTheCurrentMonth(incomesVecBalance);
//    displayExpensesForTheCurrentMonth(expensesVecBalance);
}

