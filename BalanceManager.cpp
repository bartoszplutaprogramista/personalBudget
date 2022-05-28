#include "BalanceManager.h"

float BalanceManager::displayIncomesForTheCurrentMonth(vector <Incomes> incomesVecBalance, int deletingInt, char choiceMenu){
    string dateFromIncomesVec="", dateFromIncomesVecDeleted="";
    int dateIntFromIncomesVecDeleted = 0, counter = 0;
    float incomesAmountTotal = 0;


    if(choiceMenu == '3'){
        cout << "TWOJE PRZYCHODY Z BIEZACEGO MIESIACA: " << endl;
    } else {
        cout << "TWOJE PRZYCHODY Z POPRZEDNIEGO MIESIACA: " << endl;
    }

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
    if (counter == 0){
        cout << "Nie wprowadzono zadnych przychodow w ";
        if(choiceMenu == '3'){
            cout << "biezacym miesiacu" << endl;
        } else {
            cout << "poprzednim miesiacu" << endl;
        }
    }
    getch();
    return incomesAmountTotal;
}

float BalanceManager::displayExpensesForTheCurrentMonth(vector <Expenses> expensesVecBalance, int deletingInt, char choiceMenu){
    string dateFromExpensesVec="", dateFromExpensesVecDeleted="";
    int dateIntFromExpensesVecDeleted = 0, counter = 0;
    float expansesAmountTotal = 0;

//    dateInt = AuxiliaryMethods::convertStringToInt(date);
    cout << endl;
    if(choiceMenu == '3'){
        cout << "TWOJE WYDATKI Z BIEZACEGO MIESIACA: " << endl;
    } else {
        cout << "TWOJE WYDATKI Z POPRZEDNIEGO MIESIACA: " << endl;
    }

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
    if (counter == 0){
        cout << "Nie wprowadzono zadnych wydatkow ";
        if(choiceMenu == '3'){
            cout << "biezacym miesiacu" << endl;
        } else {
            cout << "poprzednim miesiacu" << endl;
        }
    }
    getch();
    return expansesAmountTotal;
}

void BalanceManager::displayBalanceSheetForTheCurrentMonth(vector <Incomes> incomesVecBalance, vector <Expenses> expensesVecBalance, char choiceMenu){
    system("cls");
    string date="", deltingString="";
    int deletingInt = 0;
    float incomesAmountTotal = 0;
    float expansesAmountTotal = 0;
    float differenceBetweenIncomesAndExpenses = 0;

    date = AuxiliaryMethods::getSystemDate();
    deltingString = AuxiliaryMethods::deleteTheLastTwoDigits(date);
    deletingInt = AuxiliaryMethods::convertStringToInt(deltingString);

    incomesAmountTotal = displayIncomesForTheCurrentMonth(incomesVecBalance, deletingInt, choiceMenu);
    expansesAmountTotal = displayExpensesForTheCurrentMonth(expensesVecBalance, deletingInt, choiceMenu);

    cout << "Suma PRZYCHODOW z biezacego misiaca: " << incomesAmountTotal << endl;

    cout << "Suma WYDATKOW z biezacego misiaca: " << expansesAmountTotal << endl;

    differenceBetweenIncomesAndExpenses = incomesAmountTotal - expansesAmountTotal;

    cout << "Roznica pomiedzy przychodami a wydatkami: " << differenceBetweenIncomesAndExpenses << endl;
    getch();

}

bool BalanceManager::checkJanuary(string deltingString){
    string help = "";
    int helpInt = 0;
    help = AuxiliaryMethods::deleteFourFirstDigits(deltingString);
    helpInt = AuxiliaryMethods::convertStringToInt(help);
    if(helpInt == 1)
        return true;
    else
        return false;
}

/*
float BalanceManager::displayExpensesForThePreviousMonth(vector <Expenses> expensesVecBalance, int previousMonthDeletingInt){
    string dateFromExpensesVec="", dateFromExpensesVecDeleted="";
    int dateIntFromExpensesVecDeleted = 0, counter = 0;
    float expansesAmountTotal = 0;

//    dateInt = AuxiliaryMethods::convertStringToInt(date);
    cout << endl;
    cout << "TWOJE WYDATKI Z POPRZEDNIEGO MIESIACA: " << endl;

    sort(expensesVecBalance.begin(), expensesVecBalance.end(), ComparisonExpenses());

    for (int i=0; i<expensesVecBalance.size(); i++){
        dateFromExpensesVec = AuxiliaryMethods::convertIntToString(expensesVecBalance[i].getDate());
        dateFromExpensesVecDeleted = AuxiliaryMethods::deleteTheLastTwoDigits(dateFromExpensesVec);
        dateIntFromExpensesVecDeleted = AuxiliaryMethods::convertStringToInt(dateFromExpensesVecDeleted);
        if (dateIntFromExpensesVecDeleted == previousMonthDeletingInt){
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
*/

void BalanceManager::displayTheBalanceSheetForThePreviousMonth(vector <Incomes> incomesVecBalance, vector <Expenses> expensesVecBalance, char choiceMenu){
    system("cls");
    string date="", deltingString="";
    int deletingInt = 0, previousMonthDeletingInt = 0;
    bool findFirstMonthOfTheYear;
    float incomesAmountPreviousTotal = 0;
    float expansesAmountPreviousTotal = 0;
    float differenceBetweenIncomesAndExpenses = 0;

    date = AuxiliaryMethods::getSystemDate();
    deltingString = AuxiliaryMethods::deleteTheLastTwoDigits(date);
    deletingInt = AuxiliaryMethods::convertStringToInt(deltingString);

    findFirstMonthOfTheYear = checkJanuary(deltingString);

    if(findFirstMonthOfTheYear == true){
        previousMonthDeletingInt = deletingInt - 89;
    }
    else {
        previousMonthDeletingInt = deletingInt - 1;
    }

    incomesAmountPreviousTotal = displayIncomesForTheCurrentMonth(incomesVecBalance, previousMonthDeletingInt, choiceMenu);
    expansesAmountPreviousTotal = displayExpensesForTheCurrentMonth(expensesVecBalance, previousMonthDeletingInt, choiceMenu);

    cout << "Suma PRZYCHODOW z poprzedniego misiaca: " << incomesAmountPreviousTotal << endl;

    cout << "Suma WYDATKOW z poprzedniego misiaca: " << expansesAmountPreviousTotal << endl;

    differenceBetweenIncomesAndExpenses = incomesAmountPreviousTotal - expansesAmountPreviousTotal;

    cout << "Roznica pomiedzy przychodami a wydatkami: " << differenceBetweenIncomesAndExpenses << endl;
    getch();

}


