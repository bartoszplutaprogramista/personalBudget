#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int number){
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::loadLine(){
    cin.clear();
    cin.sync();
    string variableIn = "";
    getline(cin, variableIn);
    return variableIn;
}

void AuxiliaryMethods::deleteXMLFile(){
    char path[] = "users.xml";
    int remove(const char *path);
    if( remove( path ) == -1 ){
      cout << "Could not delete " << path;
      getch();
    }
}

int AuxiliaryMethods::convertStringToInt(string number){
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

bool AuxiliaryMethods::checkWetherTheDateIsGood(string date){
    if (date[4] != '-' || date[7] != '-'){
        cout << "Zly format daty sproboj jeszcze raz " << endl;
        system("pause");
        return false;
    }
    return true;
}

string AuxiliaryMethods::getSystemDate(){
    int yearToday = 0, monthToday = 0, dayToday = 0;
    string year = "", month = "", day = "";
    string wholeDate = "";
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    yearToday = now->tm_year + 1900;
    monthToday = now->tm_mon + 1;
    dayToday = now->tm_mday;

    year = convertIntToString(yearToday);
    month = convertIntToString(monthToday);
    month = addZeroBeforeMonth(month, monthToday);
    day = convertIntToString(dayToday);
    day = addZeroBeforeDay(day, dayToday);
    wholeDate = year + month + day;

    return wholeDate;
}

string AuxiliaryMethods::addZeroBeforeMonth(string variableMonth, int monthToday){
    if (monthToday < 10){
        variableMonth = "0" + variableMonth;
    }
    return variableMonth;
}

string AuxiliaryMethods::addZeroBeforeDay(string variableDay, int dayToday){
    if (dayToday < 10){
        variableDay = "0" + variableDay;
    }
    return variableDay;
}

string AuxiliaryMethods::deleteTheLastTwoDigits(string deletingString){
    deletingString.erase (6,2);
    return deletingString;
}
