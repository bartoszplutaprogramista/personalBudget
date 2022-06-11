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
};

#endif
