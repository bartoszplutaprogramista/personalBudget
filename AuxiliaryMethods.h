#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H
#include <iostream>
#include "Markup.h"
#include "User.h"
#include <sstream>
#include <conio.h>

using namespace std;

class AuxiliaryMethods{

public:
    static string convertIntToString(int number);
    static string loadLine();
    static void deleteXMLFile();
};

#endif
