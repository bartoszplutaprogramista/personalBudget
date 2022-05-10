#include "Expenses.h"

void Expenses::setExpensesId(int newIncomeId){
    if (newIncomeId >= 0)
    expenseId = newIncomeId;
}
void Expenses::setUserId(int newUserId){
    if (newUserId >= 0)
    userId = newUserId;
}
void Expenses::setDate(string newDate){
    date = newDate;
}
void Expenses::setItem(string newItem){
    item = newItem;
}
void Expenses::setAmount(string newAmount){
    amount = newAmount;
}
int Expenses::getExpensesId(){
    return expenseId;
}
int Expenses::getUserId(){
    return userId;
}
string Expenses::getDate(){
    return date;
}
string Expenses::getItem(){
    return item;
}
string Expenses::getAmount(){
    return amount;
}
