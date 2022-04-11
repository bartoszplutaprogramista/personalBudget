#include "Incomes.h"

void IncomesExpenses::setIncomeId(int newIncomeId){
    if (newIncomeId >= 0)
    incomeId = newIncomeId;
}
void IncomesExpenses::setUserId(int newUserId){
    if (newUserId >= 0)
    userId = newUserId;
}
void IncomesExpenses::setDate(string newDate){
    date = newDate;
}
void IncomesExpenses::setItem(string newItem){
    item = newItem;
}
void IncomesExpenses::setAmount(string newAmount){
    amount = newAmount;
}
int IncomesExpenses::getIncomeId(){
    return incomeId;
}
int IncomesExpenses::getUserId(){
    return userId;
}
string IncomesExpenses::getDate(){
    return date;
}
string IncomesExpenses::getItem(){
    return item;
}
string IncomesExpenses::getAmount(){
    return amount;
}
