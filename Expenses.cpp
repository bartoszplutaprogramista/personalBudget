#include "Expenses.h"

void Expenses::setExpensesId(int newIncomeId){
    if (newIncomeId >= 0)
    expenseId = newIncomeId;
}
void Expenses::setUserId(int newUserId){
    if (newUserId >= 0)
    userId = newUserId;
}
void Expenses::setDate(int newDate){
    date = newDate;
}
void Expenses::setItem(string newItem){
    item = newItem;
}
void Expenses::setAmount(float newAmount){
    amount = newAmount;
}
int Expenses::getExpensesId(){
    return expenseId;
}
int Expenses::getUserId(){
    return userId;
}
int Expenses::getDate(){
    return date;
}
string Expenses::getItem(){
    return item;
}
float Expenses::getAmount(){
    return amount;
}
