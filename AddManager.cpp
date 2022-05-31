#include "AddManager.h"

int AddManager::addExpense(){
    system("cls");
    Expenses expenses;
    FileXMLExpenses fileXMLExpenses;

        expenses = writeNewThingsOfExpenses();

    expensesVec.push_back(expenses);

    fileXMLExpenses.addExpenseToTheFile(expenses);
//    wyswietl();
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
 //       return fileXMLIncomes.getLastNumberOfIncomeID() + 1;
        return help;
//        return incomesVec.back().getIncomeId() + 1;
//fileXMLIncomes.getLastNumberOfIncomeID() + 1;
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
//    cout << "incomeID W TEJ FUNKCJI: " << incomeID << endl;
//    getch();
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
//    wyswietl();
    cout << endl << "Przychod dodano pomyslnie" << endl << endl;
    system("pause");
    return 0;

}

/*
void AddManager::wyswietl(){
    int incomesVecSize = incomesVec.size();
    for (int i=0; i<incomesVecSize; i++){
        cout << "getIncomeId: " << incomesVec[i].getIncomeId() << endl;
        cout << "getUserId: " << incomesVec[i].getUserId() << endl;
        cout << "getDate: " << incomesVec[i].getDate() << endl;
        cout << "getItem: " << incomesVec[i].getItem() << endl;
        cout << "getAmount: " << incomesVec[i].getAmount() << endl;
    }
    system("pause");
} */

int AddManager::getIDOfNewUser(){
    FileXMLIncomes fileXMLIncomes;
    int help = 0;
    int help2 = 0;
        help2 = fileXMLIncomes.getLastNumberOfIncomeID();
    if ( help2 == 0)
        return 1;
    else
        help = fileXMLIncomes.getLastNumberOfIncomeID() + 1;
 //       return fileXMLIncomes.getLastNumberOfIncomeID() + 1;
        return help;
//        return incomesVec.back().getIncomeId() + 1;
//fileXMLIncomes.getLastNumberOfIncomeID() + 1;
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
//    cout << "incomeID W TEJ FUNKCJI: " << incomeID << endl;
//    getch();
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

/*
string AddManager::getSystemDate(){
    int yearToday = 0, monthToday = 0, dayToday = 0;
    string year = "", month = "", day = "";
    string wholeDate = "";
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    yearToday = now->tm_year + 1900;
    monthToday = now->tm_mon + 1;
    dayToday = now->tm_mday;

    year = AuxiliaryMethods::convertIntToString(yearToday);
    month = AuxiliaryMethods::convertIntToString(monthToday);
    month = addZeroBeforeMonth(month, monthToday);
    day = AuxiliaryMethods::convertIntToString(dayToday);
    day = addZeroBeforeDay(day, dayToday);
    wholeDate = year + month + day;

    return wholeDate;
}
*/

/*
string AddManager::addZeroBeforeMonth(string variableMonth, int monthToday){
    if (monthToday < 10){
        variableMonth = "0" + variableMonth;
    }
    return variableMonth;
}
*/

/*
string AddManager::addZeroBeforeDay(string variableDay, int dayToday){
    if (dayToday < 10){
        variableDay = "0" + variableDay;
    }
    return variableDay;
}
*/

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

    /*
        for (int i=0; i<incomesVec.size(); i++){
            cout << "incomeId PO ZALADOWANIU: " << incomesVec[i].getIncomeId() << endl;
            cout << "userId PO ZALADOWANIU: " << incomesVec[i].getUserId() << endl;
            cout << "date PO ZALADOWANIU: " << incomesVec[i].getDate() << endl;
            cout << "item PO ZALADOWANIU:  " << incomesVec[i].getItem() << endl;
            cout << "amount PO ZALADOWANIU: " << incomesVec[i].getAmount() << endl;
        }
        getch(); */
}

void AddManager::loadDataOfExpensesIntoAVector(){
    FileXMLExpenses fileXMLExpenses;

    expensesVec = fileXMLExpenses.loadDataOfExpensesIntoAnAuxiliaryVector(LOGGED_IN_USER_ID);

    /*
        for (int i=0; i<incomesVec.size(); i++){
            cout << "incomeId PO ZALADOWANIU: " << incomesVec[i].getIncomeId() << endl;
            cout << "userId PO ZALADOWANIU: " << incomesVec[i].getUserId() << endl;
            cout << "date PO ZALADOWANIU: " << incomesVec[i].getDate() << endl;
            cout << "item PO ZALADOWANIU:  " << incomesVec[i].getItem() << endl;
            cout << "amount PO ZALADOWANIU: " << incomesVec[i].getAmount() << endl;
        }
        getch(); */
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
