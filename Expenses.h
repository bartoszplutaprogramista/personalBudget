#ifndef EXPENSES_H
#define EXPENSES_H
#include <iostream>

using namespace std;

class Expenses{
    int expenseId;
    int userId;
    int date;
    string item;
    float amount;
public:
    void setExpensesId(int newExpensesId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

    int getExpensesId();
    int getUserId();
    int getDate();
    string getItem();
    float getAmount();
};

#endif
