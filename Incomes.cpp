#include "Incomes.h"

void Incomes::setIncomeId(int newIncomeId){
    if (newIncomeId >= 0)
    incomeId = newIncomeId;
}
void Incomes::setUserId(int newUserId){
    if (newUserId >= 0)
    userId = newUserId;
}
void Incomes::setDate(int newDate){
    date = newDate;
}
void Incomes::setItem(string newItem){
    item = newItem;
}
void Incomes::setAmount(float newAmount){
    amount = newAmount;
}
int Incomes::getIncomeId(){
    return incomeId;
}
int Incomes::getUserId(){
    return userId;
}
int Incomes::getDate(){
    return date;
}
string Incomes::getItem(){
    return item;
}
float Incomes::getAmount(){
    return amount;
}
