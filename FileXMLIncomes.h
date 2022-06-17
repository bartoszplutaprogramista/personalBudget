#ifndef FILEXMLINCOMES_H
#define FILEXMLINCOMES_H
#include <iostream>
#include <sstream>
#include <vector>
#include <conio.h>
#include "Markup.h"
#include "Incomes.h"
#include "AuxiliaryMethods.h"
#include "Date.h"

using namespace std;

class FileXMLIncomes{
    CMarkup xml;
    Incomes incomes;
public:
    void addIncomeToTheFile(Incomes incomes);
    vector <Incomes> loadDataOfIncomesIntoAnAuxiliaryVector(const int LOGGED_IN_USER_ID);
    int getLastNumberOfIncomeID();
};

#endif
