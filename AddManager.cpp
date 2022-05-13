#include "AddManager.h"

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

Incomes AddManager::writeToday(){
    Incomes incomes;
    string date;
    string item;
    string yearMonthDay = "";
    int dateInt = 0;
    float incomesFloat;
    string amountText, amountTextDot;

    incomeID++;
    incomes.setIncomeId(incomeID);

    incomes.setUserId(LOGGED_IN_USER_ID);

    date = getSystemDate();
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

    incomeID++;
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

string AddManager::addZeroBeforeMonth(string variableMonth, int monthToday){
    if (monthToday < 10){
        variableMonth = "0" + variableMonth;
    }
    return variableMonth;
}

string AddManager::addZeroBeforeDay(string variableDay, int dayToday){
    if (dayToday < 10){
        variableDay = "0" + variableDay;
    }
    return variableDay;
}

string AddManager::getYearMonthDay(string date){
    string yearMonthDay;
    string pojedynczaDanaUzytkownika = "";

    for (int pozycjaZnaku = 0; pozycjaZnaku < date.length(); pozycjaZnaku++){
        if (date[pozycjaZnaku] != '-'){
            pojedynczaDanaUzytkownika += date[pozycjaZnaku];
        }
    }
        yearMonthDay = pojedynczaDanaUzytkownika;
    return yearMonthDay;
}
