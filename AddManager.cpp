#include "AddManager.h"

int AddManager::addExpense(){
    system("cls");
    Expenses expenses;
    FileXMLExpenses fileXMLExpenses;

        expenses = writeNewThingsOfExpenses();

    expensesVec.push_back(expenses);

    fileXMLExpenses.addExpenseToTheFile(expenses);
    cout << endl << "Wydatek dodano pomyslnie" << endl << endl;
    system("pause");
    return 0;

}

Expenses AddManager::writeNewThingsOfExpenses(){
    Expenses expenses;
    string date;
    char choice;
    cout << "Dodaj wydatek" << endl;
    cout << "1. Z dniem dzisiejszym" << endl;
    cout << "2. Inna data" << endl;
    cin >> choice;

    if (choice == '1'){
        expenses = writeTodayExpenses();
    } else {
        cout << "Wprowadz date format RRRR-MM-DD: ";
        date = AuxiliaryMethods::loadLine();
        if (AuxiliaryMethods::checkWetherTheDateIsGood(date)==true){
            expenses = writeWithAnotherDateOfExpenses(date);
        } else {
            system("cls");
            expenses = writeNewThingsOfExpenses();
        }
    }
return expenses;
}

int AddManager::getIDOfNewUserOfExpenses(){
    FileXMLExpenses fileXMLExpenses;
    int help = 0;
    int help2 = 0;
        help2 = fileXMLExpenses.getLastNumberOfExpenseID();
    if ( help2 == 0)
        return 1;
    else
        help = fileXMLExpenses.getLastNumberOfExpenseID() + 1;
        return help;
}

Expenses AddManager::writeWithAnotherDateOfExpenses(string date){
    Expenses expenses;
    string item;
    string yearMonthDay = "";
    int dateInt = 0;
    float expensesFloat;
    string amountText, amountTextDot;

    expenseID = getIDOfNewUserOfExpenses();
    expenses.setExpensesId(expenseID);

    expenses.setUserId(LOGGED_IN_USER_ID);

    yearMonthDay = getYearMonthDay(date);
    dateInt = AuxiliaryMethods::convertStringToInt(yearMonthDay);
    expenses.setDate(dateInt);

    cout << "Czego dotyczy wydatek: ";
    item = AuxiliaryMethods::loadLine();
    expenses.setItem(item);

    cout << "Podaj wysokosc wydatku: ";
    amountText = AuxiliaryMethods::loadLine();
    amountTextDot = checkTheComma(amountText);

    expensesFloat=atof(amountTextDot.c_str());

    expenses.setAmount(expensesFloat);

    return expenses;
}

Expenses AddManager::writeTodayExpenses(){
    Expenses expenses;
    string date;
    string item;
    string yearMonthDay = "";
    int dateInt = 0;
    float expensesFloat;
    string amountText, amountTextDot;


    expenseID = getIDOfNewUserOfExpenses();
    expenses.setExpensesId(expenseID);

    expenses.setUserId(LOGGED_IN_USER_ID);

    date = AuxiliaryMethods::getSystemDate();
    dateInt = AuxiliaryMethods::convertStringToInt(date);
    expenses.setDate(dateInt);

    cout << "Czego dotyczy wydatek: ";
    item = AuxiliaryMethods::loadLine();
    expenses.setItem(item);

    cout << "Podaj wysokosc wydatku: ";
    amountText = AuxiliaryMethods::loadLine();
    amountTextDot = checkTheComma(amountText);

    expensesFloat=atof(amountTextDot.c_str());

    expenses.setAmount(expensesFloat);

    return expenses;
}


int AddManager::addIncome(){
    system("cls");
    Incomes incomes;
    FileXMLIncomes fileXMLIncomes;

        incomes = writeNewThings();

    incomesVec.push_back(incomes);

    fileXMLIncomes.addIncomeToTheFile(incomes);
    cout << endl << "Przychod dodano pomyslnie" << endl << endl;
    system("pause");
    return 0;

}

int AddManager::getIDOfNewUser(){
    FileXMLIncomes fileXMLIncomes;
    int help = 0;
    int help2 = 0;
        help2 = fileXMLIncomes.getLastNumberOfIncomeID();
    if ( help2 == 0)
        return 1;
    else
        help = fileXMLIncomes.getLastNumberOfIncomeID() + 1;
        return help;
}

Incomes AddManager::writeToday(){
    Incomes incomes;
    string date;
    string item;
    string yearMonthDay = "";
    int dateInt = 0;
    float incomesFloat;
    string amountText, amountTextDot;


    incomeID = getIDOfNewUser();
    incomes.setIncomeId(incomeID);

    incomes.setUserId(LOGGED_IN_USER_ID);

    date = AuxiliaryMethods::getSystemDate();
    dateInt = AuxiliaryMethods::convertStringToInt(date);
    incomes.setDate(dateInt);

    cout << "Czego dotyczy przychod: ";
    item = AuxiliaryMethods::loadLine();
    incomes.setItem(item);

    cout << "Podaj wysokosc przychodu: ";
    amountText = AuxiliaryMethods::loadLine();
    amountTextDot = checkTheComma(amountText);

    incomesFloat=atof(amountTextDot.c_str());

    incomes.setAmount(incomesFloat);

    return incomes;
}

Incomes AddManager::writeWithAnotherDate(string date){
    Incomes incomes;
    string item;
    string yearMonthDay = "";
    int dateInt = 0;
    float incomesFloat;
    string amountText, amountTextDot;

    incomeID = getIDOfNewUser();
    incomes.setIncomeId(incomeID);

    incomes.setUserId(LOGGED_IN_USER_ID);

    yearMonthDay = getYearMonthDay(date);
    dateInt = AuxiliaryMethods::convertStringToInt(yearMonthDay);
    incomes.setDate(dateInt);

    cout << "Czego dotyczy przychod: ";
    item = AuxiliaryMethods::loadLine();
    incomes.setItem(item);

    cout << "Podaj wysokosc przychodu: ";
    amountText = AuxiliaryMethods::loadLine();
    amountTextDot = checkTheComma(amountText);

    incomesFloat=atof(amountTextDot.c_str());

    incomes.setAmount(incomesFloat);

    return incomes;
}

Incomes AddManager::writeNewThings(){
    Incomes incomes;
    string date;
    char choice;
    cout << "Dodaj przychod" << endl;
    cout << "1. Z dniem dzisiejszym" << endl;
    cout << "2. Inna data" << endl;
    cin >> choice;

    if (choice == '1'){
        incomes = writeToday();
    } else {
        cout << "Wprowadz date format RRRR-MM-DD: ";
        date = AuxiliaryMethods::loadLine();
        if (AuxiliaryMethods::checkWetherTheDateIsGood(date)==true){
            incomes = writeWithAnotherDate(date);
        } else {
            system("cls");
            incomes = writeNewThings();
        }
    }
return incomes;
}

string AddManager::checkTheComma(string amountText){
    for (int i = 0; i < amountText.length(); i++){
        if (amountText[i] == ','){
            amountText[i] = '.';
        }
    }
    return amountText;
}

string AddManager::getYearMonthDay(string date){
    string yearMonthDay;
    string singleUserData = "";

    for (int markPosition = 0; markPosition < date.length(); markPosition++){
        if (date[markPosition] != '-'){
            singleUserData += date[markPosition];
        }
    }
        yearMonthDay = singleUserData;
    return yearMonthDay;
}

void AddManager::loadDataOfIncomesIntoAVector(){
    FileXMLIncomes fileXMLIncomes;

    incomesVec = fileXMLIncomes.loadDataOfIncomesIntoAnAuxiliaryVector(LOGGED_IN_USER_ID);
}

void AddManager::loadDataOfExpensesIntoAVector(){
    FileXMLExpenses fileXMLExpenses;

    expensesVec = fileXMLExpenses.loadDataOfExpensesIntoAnAuxiliaryVector(LOGGED_IN_USER_ID);
}

vector <Incomes> AddManager::getIncomesVec(){
    return incomesVec;
}

vector <Expenses> AddManager::getExpensesVec(){
    return expensesVec;
}

int AddManager::getLOGGED_IN_USER_ID(){
    return LOGGED_IN_USER_ID;
}
