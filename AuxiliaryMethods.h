#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H
#include <iostream>
#include "Markup.h"
#include "User.h"
#include <sstream>
#include <conio.h>
#include <ctime>
#include <string>

using namespace std;

class AuxiliaryMethods{

public:
    static string convertIntToString(int number);
    static string loadLine();
    static void deleteXMLFile();
    static int convertStringToInt(string number);
    static bool checkWetherTheDateIsGood(string date);
    static string getSystemDate();
    static string addZeroBeforeMonth(string variableMonth, int monthToday);
    static string addZeroBeforeDay(string variableDay, int dayToday);
    static string deleteTheLastTwoDigits(string deletingString);
    static string deleteFourFirstDigits(string deletingString);
    static bool checkWetherSelectedPeriodIsGood(string datePeriod);
    static string getTwoDatesFromSelectedPeriod(string datePeriod);
    static string divideStringAndSaveFirstDate(string joinedDate);
    static string divideStringAndSaveSecondDate(string joinedDate);
    static string insertDashes(string date);

};

#endif
