#include "BalanceManager.h"

float BalanceManager::displayIncomesForTheCurrentMonth(vector <Incomes> incomesVecBalance, int deletingInt){
    string dateFromIncomesVec="", dateFromIncomesVecDeleted="";
    int dateIntFromIncomesVecDeleted = 0, counter = 0;
    float incomesAmountTotal = 0;


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
            cout << endl;
            incomesAmountTotal += incomesVecBalance[i].getAmount();
            counter++;
        }
    }
    getch();
    if (counter == 0){
        cout << "Nie wprowadzono zadnych przychodow w biezacym miesiacu" << endl;
        getch();
    }
    return incomesAmountTotal;
}

float BalanceManager::displayExpensesForTheCurrentMonth(vector <Expenses> expensesVecBalance, int deletingInt){
    string dateFromExpensesVec="", dateFromExpensesVecDeleted="";
    int dateIntFromExpensesVecDeleted = 0, counter = 0;
    float expansesAmountTotal = 0;

//    dateInt = AuxiliaryMethods::convertStringToInt(date);
    cout << endl;
    cout << "TWOJE WYDATKI Z BIEZACEGO MIESIACA: " << endl;

    sort(expensesVecBalance.begin(), expensesVecBalance.end(), ComparisonExpenses());

    for (int i=0; i<expensesVecBalance.size(); i++){
        dateFromExpensesVec = AuxiliaryMethods::convertIntToString(expensesVecBalance[i].getDate());
        dateFromExpensesVecDeleted = AuxiliaryMethods::deleteTheLastTwoDigits(dateFromExpensesVec);
        dateIntFromExpensesVecDeleted = AuxiliaryMethods::convertStringToInt(dateFromExpensesVecDeleted);
        if (dateIntFromExpensesVecDeleted == deletingInt){
            cout << "Data: " << expensesVecBalance[i].getDate() << endl;
            cout << "Przychod:  " << expensesVecBalance[i].getItem() << endl;
            cout << "Kwota: " << expensesVecBalance[i].getAmount() << endl;
            cout << endl;
            expansesAmountTotal += expensesVecBalance[i].getAmount();
            counter++;
        }
    }
    getch();
    if (counter == 0){
        cout << "Nie wprowadzono zadnych wydatkow w biezacym miesiacu" << endl;
        getch();
    }
    return expansesAmountTotal;
}

void BalanceManager::displayBalanceSheetForTheCurrentMonth(vector <Incomes> incomesVecBalance, vector <Expenses> expensesVecBalance){
    system("cls");
    string date="", deltingString="";
    int deletingInt = 0;
    float incomesAmountTotal = 0;
    float expansesAmountTotal = 0;
    float differenceBetweenIncomesAndExpenses = 0;

    date = AuxiliaryMethods::getSystemDate();
    deltingString = AuxiliaryMethods::deleteTheLastTwoDigits(date);
    deletingInt = AuxiliaryMethods::convertStringToInt(deltingString);

    incomesAmountTotal = displayIncomesForTheCurrentMonth(incomesVecBalance, deletingInt);
    expansesAmountTotal = displayExpensesForTheCurrentMonth(expensesVecBalance, deletingInt);

    cout << "Suma PRZYCHODOW z biezacego misiaca: " << incomesAmountTotal << endl;

    cout << "Suma WYDATKOW z biezacego misiaca: " << expansesAmountTotal << endl;

    differenceBetweenIncomesAndExpenses = incomesAmountTotal - expansesAmountTotal;

    cout << "Roznica pomiedzy przychodami a wydatkami: " << differenceBetweenIncomesAndExpenses << endl;
    getch();

}

