#include "BalanceManager.h"

float BalanceManager::displayIncomesForTheCurrentOrPreviousMonth(vector <Incomes> incomesVecBalance, int deletingInt, char choiceMenu){
    string dateFromIncomesVec="", dateFromIncomesVecDeleted="", incomesDateOfCurrentOrPreviousMonth ="", incomesDateOfCurrentOrPreviousMonthWithDashes ="";
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
        dateFromIncomesVecDeleted = Date::deleteTheLastTwoDigits(dateFromIncomesVec);
        dateIntFromIncomesVecDeleted = AuxiliaryMethods::convertStringToInt(dateFromIncomesVecDeleted);
        if (dateIntFromIncomesVecDeleted == deletingInt){
            incomesDateOfCurrentOrPreviousMonth = AuxiliaryMethods::convertIntToString(incomesVecBalance[i].getDate());
            incomesDateOfCurrentOrPreviousMonthWithDashes = Date::insertDashes(incomesDateOfCurrentOrPreviousMonth);
            cout << "Data: " << incomesDateOfCurrentOrPreviousMonthWithDashes << endl;
            cout << "Przychod:  " << incomesVecBalance[i].getItem() << endl;
            cout << "Kwota: " << fixed << setprecision(2) << incomesVecBalance[i].getAmount() << endl;
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

float BalanceManager::displayExpensesForTheCurrentOrPreviousMonth(vector <Expenses> expensesVecBalance, int deletingInt, char choiceMenu){
    string dateFromExpensesVec="", dateFromExpensesVecDeleted="", expensesDateOfCurrentOrPreviousMonth ="", expensesDateOfCurrentOrPreviousMonthWithDashes ="";
    int dateIntFromExpensesVecDeleted = 0, counter = 0;
    float expansesAmountTotal = 0;

    cout << endl;
    if(choiceMenu == '3'){
        cout << "TWOJE WYDATKI Z BIEZACEGO MIESIACA: " << endl;
    } else {
        cout << "TWOJE WYDATKI Z POPRZEDNIEGO MIESIACA: " << endl;
    }

    sort(expensesVecBalance.begin(), expensesVecBalance.end(), ComparisonExpenses());

    for (int i=0; i<expensesVecBalance.size(); i++){
        dateFromExpensesVec = AuxiliaryMethods::convertIntToString(expensesVecBalance[i].getDate());
        dateFromExpensesVecDeleted = Date::deleteTheLastTwoDigits(dateFromExpensesVec);
        dateIntFromExpensesVecDeleted = AuxiliaryMethods::convertStringToInt(dateFromExpensesVecDeleted);
        if (dateIntFromExpensesVecDeleted == deletingInt){
            expensesDateOfCurrentOrPreviousMonth = AuxiliaryMethods::convertIntToString(expensesVecBalance[i].getDate());
            expensesDateOfCurrentOrPreviousMonthWithDashes = Date::insertDashes(expensesDateOfCurrentOrPreviousMonth);
            cout << "Data: " << expensesDateOfCurrentOrPreviousMonthWithDashes << endl;
            cout << "Przychod:  " << expensesVecBalance[i].getItem() << endl;
            cout << "Kwota: " << fixed << setprecision(2) << expensesVecBalance[i].getAmount() << endl;
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

    date = Date::getSystemDate();
    deltingString = Date::deleteTheLastTwoDigits(date);
    deletingInt = AuxiliaryMethods::convertStringToInt(deltingString);

    incomesAmountTotal = displayIncomesForTheCurrentOrPreviousMonth(incomesVecBalance, deletingInt, choiceMenu);
    expansesAmountTotal = displayExpensesForTheCurrentOrPreviousMonth(expensesVecBalance, deletingInt, choiceMenu);

    if(incomesAmountTotal != 0){
        cout << "Suma PRZYCHODOW z biezacego misiaca: " <<  incomesAmountTotal << endl;
    }

    if(expansesAmountTotal != 0){
        cout << "Suma WYDATKOW z biezacego misiaca: " << fixed << setprecision(2) << expansesAmountTotal << endl;
    }

    differenceBetweenIncomesAndExpenses = incomesAmountTotal - expansesAmountTotal;

    if(differenceBetweenIncomesAndExpenses != 0){
        cout << fixed << "Roznica pomiedzy przychodami a wydatkami: " << fixed << setprecision(2) << differenceBetweenIncomesAndExpenses << endl;
    }

    if(incomesAmountTotal != 0 || expansesAmountTotal != 0){
        getch();
    }
}

bool BalanceManager::checkJanuary(string deltingString){
    string help = "";
    int helpInt = 0;
    help = Date::deleteFourFirstDigits(deltingString);
    helpInt = AuxiliaryMethods::convertStringToInt(help);
    if(helpInt == 1)
        return true;
    else
        return false;
}

void BalanceManager::displayTheBalanceSheetForThePreviousMonth(vector <Incomes> incomesVecBalance, vector <Expenses> expensesVecBalance, char choiceMenu){
    system("cls");
    string date="", deltingString="";
    int deletingInt = 0, previousMonthDeletingInt = 0;
    bool findFirstMonthOfTheYear;
    float incomesAmountPreviousTotal = 0;
    float expansesAmountPreviousTotal = 0;
    float differenceBetweenIncomesAndExpenses = 0;

    date = Date::getSystemDate();
    deltingString = Date::deleteTheLastTwoDigits(date);
    deletingInt = AuxiliaryMethods::convertStringToInt(deltingString);

    findFirstMonthOfTheYear = checkJanuary(deltingString);

    if(findFirstMonthOfTheYear == true){
        previousMonthDeletingInt = deletingInt - 89;
    }
    else {
        previousMonthDeletingInt = deletingInt - 1;
    }

    incomesAmountPreviousTotal = displayIncomesForTheCurrentOrPreviousMonth(incomesVecBalance, previousMonthDeletingInt, choiceMenu);
    expansesAmountPreviousTotal = displayExpensesForTheCurrentOrPreviousMonth(expensesVecBalance, previousMonthDeletingInt, choiceMenu);

    if(incomesAmountPreviousTotal != 0){
        cout << "Suma PRZYCHODOW z poprzedniego misiaca: " << fixed << setprecision(2) << incomesAmountPreviousTotal << endl;
    }

    if(expansesAmountPreviousTotal != 0){
        cout << "Suma WYDATKOW z poprzedniego misiaca: " << fixed << setprecision(2) << expansesAmountPreviousTotal << endl;
    }

    differenceBetweenIncomesAndExpenses = incomesAmountPreviousTotal - expansesAmountPreviousTotal;

    if(differenceBetweenIncomesAndExpenses != 0){
        cout << "Roznica pomiedzy przychodami a wydatkami: " << fixed << setprecision(2) << differenceBetweenIncomesAndExpenses << endl;
    }

    if(incomesAmountPreviousTotal != 0 || expansesAmountPreviousTotal != 0){
        getch();
    }
}

float BalanceManager::showTheBalanceSheetForTheSelectedPeriodIncomes(vector <Incomes> incomesVecBalance, int firstDateInt, int secondDateInt){
    int counter = 0;
    float incomesAmountTotal = 0;
    string incomesDateOfSelectedPeriod = "", incomesDateOfSelectedPeriodWithDashes = "";

    cout << "TWOJE PRZYCHODY Z WYBRANEGO OKRESU: " << endl;

    sort(incomesVecBalance.begin(), incomesVecBalance.end(), Comparison());
    for (int i=0; i<incomesVecBalance.size(); i++){
        if (incomesVecBalance[i].getDate() >= firstDateInt && incomesVecBalance[i].getDate() <= secondDateInt){
            incomesDateOfSelectedPeriod = AuxiliaryMethods::convertIntToString(incomesVecBalance[i].getDate());
            incomesDateOfSelectedPeriodWithDashes = Date::insertDashes(incomesDateOfSelectedPeriod);
            cout << "Data: " << incomesDateOfSelectedPeriodWithDashes << endl;
            cout << "Przychod:  " << incomesVecBalance[i].getItem() << endl;
            cout << "Kwota: " << fixed << setprecision(2) << incomesVecBalance[i].getAmount() << endl;
            cout << endl;
            incomesAmountTotal += incomesVecBalance[i].getAmount();
            counter++;
        }
    }
    if (counter == 0){
        cout << "Nie wprowadzono zadnych przychodow w tym okresie" << endl;
    }
    getch();
    return incomesAmountTotal;
}

float BalanceManager::showTheBalanceSheetForTheSelectedPeriodExpenses(vector <Expenses> expensesVecBalance, int firstDateInt, int secondDateInt){
    int counter = 0;
    float expensesAmountTotal = 0;
    string expensesDateOfSelectedPeriod = "", expensesDateOfSelectedPeriodWithDashes = "";

    cout << "TWOJE WYDATKI Z WYBRANEGO OKRESU: " << endl;

    sort(expensesVecBalance.begin(), expensesVecBalance.end(), ComparisonExpenses());
    for (int i=0; i<expensesVecBalance.size(); i++){
        if (expensesVecBalance[i].getDate() >= firstDateInt && expensesVecBalance[i].getDate() <= secondDateInt){
            expensesDateOfSelectedPeriod = AuxiliaryMethods::convertIntToString(expensesVecBalance[i].getDate());
            expensesDateOfSelectedPeriodWithDashes = Date::insertDashes(expensesDateOfSelectedPeriod);
            cout << "Data: " << expensesDateOfSelectedPeriodWithDashes << endl;
            cout << "Wydatek:  " << expensesVecBalance[i].getItem() << endl;
            cout << "Kwota: " << fixed << setprecision(2) << expensesVecBalance[i].getAmount() << endl;
            cout << endl;
            expensesAmountTotal += expensesVecBalance[i].getAmount();
            counter++;
        }
    }
    if (counter == 0){
        cout << "Nie wprowadzono zadnych wydatkow w tym okresie" << endl;
    }
    getch();
    return expensesAmountTotal;
}

void BalanceManager::displaySumOfExpensesAndIncomesForTheSelectedPeriod(float incomesAmountTotalPeriod, float expensesAmountTotalPeriod){
    cout << endl;
    float differenceBetweenIncomesAndExpensesInPeriodOfTime = 0;
    if(incomesAmountTotalPeriod != 0){
        cout << "Suma PRZYCHODOW z wybranego okresu: " << fixed << setprecision(2) << incomesAmountTotalPeriod << endl;
    }

    if(expensesAmountTotalPeriod != 0){
        cout << "Suma WYDATKOW z wybranego okresu: " << fixed << setprecision(2) << expensesAmountTotalPeriod << endl;
    }

    differenceBetweenIncomesAndExpensesInPeriodOfTime = incomesAmountTotalPeriod - expensesAmountTotalPeriod;

    if(differenceBetweenIncomesAndExpensesInPeriodOfTime != 0){
        cout << "Roznica pomiedzy przychodami a wydatkami z wybranego okresu: " << fixed << setprecision(2) << differenceBetweenIncomesAndExpensesInPeriodOfTime << endl;
    }

    if(incomesAmountTotalPeriod != 0 || expensesAmountTotalPeriod != 0){
        getch();
    }
}

void BalanceManager::displayTheBalanceForTheSelectedPeriod(vector <Incomes> incomesVecBalance, vector <Expenses> expensesVecBalance){
    system("cls");
    string firstDate = "", secondDate = "", firstDateWithoutDashes = "", secondDateWithoutDashes = "";
    int firstDateInt = 0, secondDateInt = 0;
    float incomesAmountTotalPeriod = 0, expensesAmountTotalPeriod = 0;
    cout << "Wprowadz okres z ktorego chcesz rozliczenie format najpierw pierwsza data: RRRR-MM-DD" << endl;
    firstDate = AuxiliaryMethods::loadLine();
    if(Date::checkWetherTheDateIsGood(firstDate)==true){
        cout << "Do drugiej daty: RRRR-MM-DD:" << endl;
        secondDate = AuxiliaryMethods::loadLine();
        if(Date::checkWetherTheDateIsGood(secondDate)==true){
            firstDateWithoutDashes = Date::getStringDateWithoutDashes(firstDate);
            secondDateWithoutDashes = Date::getStringDateWithoutDashes(secondDate);
            firstDateInt = AuxiliaryMethods::convertStringToInt(firstDateWithoutDashes);
            secondDateInt = AuxiliaryMethods::convertStringToInt(secondDateWithoutDashes);
            if(firstDateInt > secondDateInt){
                cout << "Pierwsza Data powinna byæ starsza niz druga. Sproboj jeszcze raz" << endl;
                getch();
                displayTheBalanceForTheSelectedPeriod(incomesVecBalance, expensesVecBalance);
            }else{
                incomesAmountTotalPeriod = showTheBalanceSheetForTheSelectedPeriodIncomes(incomesVecBalance, firstDateInt, secondDateInt);
                expensesAmountTotalPeriod = showTheBalanceSheetForTheSelectedPeriodExpenses(expensesVecBalance, firstDateInt, secondDateInt);
            }
        }else{
            displayTheBalanceForTheSelectedPeriod(incomesVecBalance, expensesVecBalance);
        }
    }else{
        displayTheBalanceForTheSelectedPeriod(incomesVecBalance, expensesVecBalance);
    }
    displaySumOfExpensesAndIncomesForTheSelectedPeriod(incomesAmountTotalPeriod, expensesAmountTotalPeriod);
}
