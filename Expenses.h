#ifndef EXPENSES_H
#define EXPENSES_H
#include <iostream>

using namespace std;

class Expenses{
    int expenseId;
    int userId;
    string date;
    string item;
    string amount;
public:
    void setExpensesId(int newExpensesId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    int getExpensesId();
    int getUserId();
    string getDate();
    string getItem();
    string getAmount();
};

#endif
