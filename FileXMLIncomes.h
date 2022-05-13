#ifndef FILEXMLINCOMES_H
#define FILEXMLINCOMES_H
#include <iostream>
#include <sstream>
#include "Markup.h"
#include "Incomes.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileXMLIncomes{
    CMarkup xml;
public:
    void addIncomeToTheFile(Incomes incomes);
};

#endif
