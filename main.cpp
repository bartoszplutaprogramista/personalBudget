#include <iostream>
#include "PersonalBudget.h"
#include <conio.h>
#include "UserManager.h"

using namespace std;


int menu(PersonalBudget &personalBudget){
    while(true) {
        char choiceMenu;
        system("cls");
        cout << "1. Dodaj przychod" << endl;
        cout << "2. Dodaj wydatek" << endl;
        cout << "3. Bilans z biezacego miesiaca" << endl;
        cout << "4. Bilans z poprzedniego miesisca" << endl;
        cout << "5. Bilans z wybranego okresu" << endl;
        cout << "6. Zmien haslo" << endl;
        cout << "7. Wyloguj sie" << endl;

        cin >> choiceMenu;
        if(choiceMenu == '1') {
            personalBudget.addIncome();
        } else if (choiceMenu == '2') {
            personalBudget.addExpense();
        } else if (choiceMenu == '3') {
            personalBudget.displayBalanceSheetForTheCurrentMonth(choiceMenu);
        } else if (choiceMenu == '4') {
            personalBudget.displayTheBalanceSheetForThePreviousMonth(choiceMenu);
        } else if (choiceMenu == '5') {
            personalBudget.displayTheBalanceForTheSelectedPeriod();
        } else if (choiceMenu == '6') {
            personalBudget.changeOfTheLoggedInUserPassword(personalBudget.getTheLoggedInUserID());
        } else if (choiceMenu == '7') {
            personalBudget.loggOutOfTheUser();
            return 0;
        }
    }
}

int main()
{
    char choice;
    int number=0;
//    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");
    PersonalBudget personalBudget;
    UserManager userManager;
    personalBudget.loadDataIntoAVector();
    while(true) {
        system("cls");
        cout << "MENU GLOWNE" << endl;
        cout << "1. Rejestracja" << endl;
        cout << "2. Logowanie" << endl;
        cout << "3. Zamknij program" << endl;
        cin >> choice;
        if(choice == '1') {
            personalBudget.userRegistration();
        } else if (choice == '2') {
            number = personalBudget.userLoggIn();
            if (number == 1){
               menu(personalBudget);
            }else {
                main();
            }
        } else if (choice == '3') {
            exit(0);
        }
    }
    return 0;
}
