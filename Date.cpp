#include "Date.h"

bool Date::checkWetherTheDateIsGood(string date){
    if (date[4] != '-' || date[7] != '-'){
        cout << "Zly format daty sproboj jeszcze raz " << endl;
        system("pause");
        return false;
    }
    return true;
}

string Date::getYearMonthDay(string date){
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

string Date::eraseStringAndGetYear(string joinedDate){
    joinedDate.erase (4,4);
    return joinedDate;
}

string Date::eraseStringAndGetMonth(string joinedDate){
    joinedDate.erase (0,4);
    joinedDate.erase (2,2);
    return joinedDate;
}

string Date::eraseStringAndGetDay(string joinedDate){
    joinedDate.erase (0,6);
    return joinedDate;
}


bool Date::checkDateValidation(string date){
    int year = 0, currentYear = 0, currentMonth = 0, month = 0,currentDay = 0, day = 0;
    string yearMonthDayString = "", yearString = "", monthString = "", dayString = "", currentDate = "", currentYearString = "", currentMonthString = "", currentDayString = "";
    currentDate = getSystemDate();
    yearMonthDayString = getYearMonthDay(date);
    yearString = eraseStringAndGetYear(yearMonthDayString);
    monthString = eraseStringAndGetMonth(yearMonthDayString);
    dayString = eraseStringAndGetDay(yearMonthDayString);
    year = AuxiliaryMethods::convertStringToInt(yearString);
    month = AuxiliaryMethods::convertStringToInt(monthString);
    day = AuxiliaryMethods::convertStringToInt(dayString);

    currentYearString = eraseStringAndGetYear(currentDate);
    currentMonthString = eraseStringAndGetMonth(currentDate);
    currentDayString = eraseStringAndGetDay(currentDate);
    currentYear = AuxiliaryMethods::convertStringToInt(currentYearString);
    currentMonth = AuxiliaryMethods::convertStringToInt(currentMonthString);
    currentDay = AuxiliaryMethods::convertStringToInt(currentDayString);

    if (((year<2000)||(year>currentYear)||(year>=currentYear&&month>currentMonth)||(year>=currentYear&&month>=currentMonth&&day>currentDay))||
        (month==1&&day>31)||
        (month==3&&day>31)||
        (month==5&&day>31)||
        (month==7&&day>31)||
        (month==8&&day>31)||
        (month==10&&day>31)||
        (month==12&&day>31)||
        (month==4&&day>30)||
        (month==6&&day>30)||
        (month==9&&day>30)||
        (month==11&&day>30)||
        (!(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))&&(month==2&&day>28))||
        ((((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))&&(month==2&&day>29))){
        cout << "Data poza zakresem!. Sprobuj jeszcze raz. " << endl;
        getch();
        return false;
    }else
        return true;
}

string Date::getSystemDate(){
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

string Date::addZeroBeforeMonth(string variableMonth, int monthToday){
    if (monthToday < 10){
        variableMonth = "0" + variableMonth;
    }
    return variableMonth;
}

string Date::addZeroBeforeDay(string variableDay, int dayToday){
    if (dayToday < 10){
        variableDay = "0" + variableDay;
    }
    return variableDay;
}

string Date::deleteTheLastTwoDigits(string deletingString){
    deletingString.erase (6,2);
    return deletingString;
}

string Date::deleteFourFirstDigits(string deletingString){
    deletingString.erase (0,4);
    return deletingString;
}

/*
bool Date::checkWetherSelectedPeriodIsGood(string datePeriod){
    if (datePeriod[4] != '-' || datePeriod[7] != '-' || datePeriod[10] != '-' || datePeriod[15] != '-' || datePeriod[18] != '-'){
        cout << "Zly format okresu rozliczeniowego sproboj jeszcze raz " << endl;
        system("pause");
        system("cls");
        return false;
    }
    return true;
} */

string Date::getStringDateWithoutDashes(string date){
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


/*
string Date::divideStringAndSaveFirstDate(string joinedDate){
    joinedDate.erase (8,8);
    return joinedDate;
}

string Date::divideStringAndSaveSecondDate(string joinedDate){
    joinedDate.erase (0,8);
    return joinedDate;
} */

string Date::insertDashes(string date){
    date.insert(4, "-");
    date.insert(7, "-");
    return date;
}
