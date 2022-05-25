#include "BalanceManager.h"

void BalanceManager::displayBalanceSheetForTheCurrentMonth(vector <Incomes> incomesVecBalance){
    system("cls");
    cout << "TWOJE PRZYCHODY Z BIEZACEGO MIESIACA: " << endl;
    for (int i=0; i<incomesVecBalance.size(); i++){
        if ()
        cout << "Data: " << incomesVecBalance[i].getDate() << endl;
        cout << "Przychod:  " << incomesVecBalance[i].getItem() << endl;
        cout << "Kwota: " << incomesVecBalance[i].getAmount() << endl;
    }
    getch();
}

