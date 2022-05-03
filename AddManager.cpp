#include "AddManager.h"

void AddManager::addIncome(){
    system("cls");
    Incomes incomes;
    char choice;
    cout << "Dodaj przychod" << endl;
    cout << "1. Z dniem dzisiejszym" << endl;
    cout << "2. Inna data" << endl;
    cin >> choice;
//    if(choice == '1') {
//        cout << "Dodaj Przychod z dniem dzisiejszym" << endl;
        incomes = writeNewThings(choice);
//    } else {
//        cout << "Dodaj Przychod z inna data" << endl;
//    }


    incomesVec.push_back(incomes);
//    fileXMLIncomes.addTheRecipientToTheFile(incomes);

    wyswietl();
    cout << endl << "Przychod dodano pomyslnie" << endl << endl;
    system("pause");

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

Incomes AddManager::writeNewThings(char choice){
    Incomes incomes;
    string date;
    string item;
    string yearMonthDay = "";
    int dateInt = 0;
    float incomesFloat;
    string amountText, amountTextDot;

//    user.setUserId(getNewUserId());

    if (choice == '1'){
        date = getSystemDate();
        cout << "date po sklejeniu: " << date << endl;
        dateInt = AuxiliaryMethods::convertStringToInt(date);
        incomes.setDate(dateInt);
        cout << "date po przeksztalceniu w INT: " << dateInt << endl;
        getch();
    } else {
        cout << "Wprowadz date format RRRR-MM-DD: ";
        date = AuxiliaryMethods::loadLine();
        if (AuxiliaryMethods::checkWetherTheDateIsGood(date)==true){
            yearMonthDay = getYearMonthDay(date);
            dateInt = AuxiliaryMethods::convertStringToInt(yearMonthDay);
            cout << "date po przeksztalceniu w INT (dowolna data): " << dateInt << endl;
            incomes.setDate(dateInt);
        } else {
            cout << "Wprowadzono zly format daty. Sproboj jeszcze raz. " << endl;
            addIncome();
        }
    }

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
    month = addZeroBefore(month, monthToday, dayToday);
    day = AuxiliaryMethods::convertIntToString(dayToday);
    day = addZeroBefore(day, monthToday, dayToday);
    wholeDate = year + month + day;

    return wholeDate;
}

string AddManager::addZeroBefore(string variable, int monthToday, int dayToday){
    if (monthToday < 10 || dayToday < 10){
        variable = "0" + variable;
    }
    return variable;
}

string AddManager::getYearMonthDay(string date){
    string yearMonthDay;
    string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

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
