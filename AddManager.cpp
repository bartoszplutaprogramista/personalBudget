#include "AddManager.h"

int AddManager::addIncome(){
    system("cls");
    Incomes incomes;
    FileXMLIncomes fileXMLIncomes;

//    if(choice == '1') {
//        cout << "Dodaj Przychod z dniem dzisiejszym" << endl;
        incomes = writeNewThings();

        cout << "incomes.getDate()" << incomes.getDate() << endl;
        cout << "incomes.getItem() " << incomes.getItem() << endl;
        cout << "incomes.getAmount()" << incomes.getAmount() << endl;
        getch();
//    } else {
//        cout << "Dodaj Przychod z inna data" << endl;
//    }


    incomesVec.push_back(incomes);
//    fileXMLIncomes.addTheRecipientToTheFile(incomes);

    fileXMLIncomes.addIncomeToTheFile(incomes);
    wyswietl();
    cout << endl << "Przychod dodano pomyslnie" << endl << endl;
    system("pause");
    return 0;

}

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
}

Incomes AddManager::writeToday(){
    Incomes incomes;
    string date;
    string item;
    string yearMonthDay = "";
    int dateInt = 0;
    float incomesFloat;
    string amountText, amountTextDot;

    cout << "INCOME ID: ";
    incomeID++;
    incomes.setIncomeId(incomeID);
    cout << incomeID << endl;
    getch();

    cout << "LOGED IN USER ID: ";
    incomes.setUserId(LOGGED_IN_USER_ID);
    cout << LOGGED_IN_USER_ID << endl;
    getch();

    date = getSystemDate();
    cout << "date po sklejeniu: " << date << endl;
    dateInt = AuxiliaryMethods::convertStringToInt(date);
    incomes.setDate(dateInt);
    cout << "date po przeksztalceniu w INT: " << dateInt << endl;
    getch();
    cout << "Czego dotyczy przychod: ";
    item = AuxiliaryMethods::loadLine();
    incomes.setItem(item);

    cout << "get item: " << incomes.getItem() << endl;
    getch();

    cout << "Podaj wysokosc przychodu: ";
    amountText = AuxiliaryMethods::loadLine();
    amountTextDot = checkTheComma(amountText);

    incomesFloat=atof(amountTextDot.c_str());
    cout << "incomesFloat " << incomesFloat << endl;

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

    cout << "INCOME ID: ";
    incomeID++;
    incomes.setIncomeId(incomeID);
    cout << incomeID << endl;
    getch();

    cout << "LOGED IN USER ID: ";
    incomes.setUserId(LOGGED_IN_USER_ID);
    cout << LOGGED_IN_USER_ID << endl;
    getch();

    yearMonthDay = getYearMonthDay(date);
    dateInt = AuxiliaryMethods::convertStringToInt(yearMonthDay);
    cout << "date po przeksztalceniu w INT (dowolna data): " << dateInt << endl;
    incomes.setDate(dateInt);

    cout << "Czego dotyczy przychod: ";
    item = AuxiliaryMethods::loadLine();
    incomes.setItem(item);

    cout << "get item: " << incomes.getItem() << endl;
    getch();

    cout << "Podaj wysokosc przychodu: ";
    amountText = AuxiliaryMethods::loadLine();
    amountTextDot = checkTheComma(amountText);

    incomesFloat=atof(amountTextDot.c_str());
    cout << "incomesFloat " << incomesFloat << endl;

    incomes.setAmount(incomesFloat);

    return incomes;
}

/*
int UserManager::getNewIncomeId(){

    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
} */

Incomes AddManager::writeNewThings(){
    Incomes incomes;
//    PersonalBudget personalBudget;
//    UserManager userManager;
    string date;
/*
    string item;
    string yearMonthDay = "";
    int dateInt = 0;
    float incomesFloat;
    string amountText, amountTextDot; */

//    user.setUserId(getNewUserId());
    char choice;
    cout << "Dodaj przychod" << endl;
    cout << "1. Z dniem dzisiejszym" << endl;
    cout << "2. Inna data" << endl;
    cin >> choice;

/*
    cout << "userManager.getTheLoggedInUserID() w wfunkcji WriteNewThings" << userManager.getTheLoggedInUserIDFromUserManager() << endl;
    system("pause");
    incomes.setUserId(#); */

    cout << "WARTOSC ZALOGOWANEGO UZYTKOWNIKA WYNOSI W FUNKCJI WRITE NEW THINGS: " << LOGGED_IN_USER_ID << endl;
    getch();



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

/*
string AddManager::addZeroBefore(string variable, int monthToday, int dayToday){
    if (monthToday < 10 || dayToday < 10){
        variable = "0" + variable;
    }
    return variable;
} */

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
        cout << "yearMonthDay OSTATECZNY " << yearMonthDay << endl;
        getch();
    return yearMonthDay;
}
