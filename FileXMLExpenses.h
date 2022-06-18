#ifndef FILEXMLEXPENSES_H
#define FILEXMLEXPENSES_H
#include <iostream>
#include <sstream>
#include <vector>
#include <conio.h>
#include "Markup.h"
#include "Expenses.h"
#include "AuxiliaryMethods.h"
#include "Date.h"

using namespace std;

class FileXMLExpenses{
    CMarkup xml;
    Expenses expenses;
public:
    void addExpenseToTheFile(Expenses expenses);
    vector <Expenses> loadDataOfExpensesIntoAnAuxiliaryVector(const int LOGGED_IN_USER_ID);
    int getLastNumberOfExpenseID();
};

#endif

